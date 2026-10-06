#include <iostream>
#include <array>
#include <memory_resource>
#include <string>
#include <vector>
using namespace std;
// pmr: los contenedores piden memoria a un "recurso" que se elige en ejecucion.
// Un monotonic_buffer_resource entrega bloques de un buffer ya reservado: sin llamadas a malloc.
struct RecursoVerbose : pmr::memory_resource {
	pmr::memory_resource *base = pmr::new_delete_resource();
	int reservas = 0, liberaciones = 0;
	size_t bytes = 0;
	void *do_allocate(size_t n, size_t a) override { reservas++; bytes += n; return base->allocate(n, a); }
	void do_deallocate(void *p, size_t n, size_t a) override { liberaciones++; base->deallocate(p, n, a); }
	bool do_is_equal(const pmr::memory_resource &o) const noexcept override { return this == &o; }
};
int main(){
	// 1) buffer en la pila
	array<std::byte, 4096> buffer;
	pmr::monotonic_buffer_resource pool(buffer.data(), buffer.size(), pmr::null_memory_resource());
	pmr::vector<int> v(&pool);
	for (int i = 0; i < 100; i++) v.push_back(i);
	cout << "v tiene " << v.size() << " elementos, todos en el buffer de la pila" << endl;
	pmr::vector<pmr::string> nombres(&pool);
	for (auto s : {"Ana", "Luis", "Rosa", "Pedro"}) nombres.emplace_back(s);
	cout << "nombres: " << nombres.size() << endl;

	// 2) contar las reservas realmente pedidas al sistema
	RecursoVerbose r1;
	{
		vector<int, pmr::polymorphic_allocator<int>> sin(&r1);
		for (int i = 0; i < 1000; i++) sin.push_back(i);
	}
	cout << "vector normal: " << r1.reservas << " reservas, " << r1.liberaciones << " liberaciones" << endl;

	RecursoVerbose r2;
	{
		pmr::monotonic_buffer_resource arena(&r2);               // pide bloques grandes a r2
		pmr::vector<int> con(&arena);
		for (int i = 0; i < 1000; i++) con.push_back(i);
		pmr::vector<int> otro(&arena);
		for (int i = 0; i < 1000; i++) otro.push_back(i);
	}
	cout << "con arena:    " << r2.reservas << " reservas, " << r2.liberaciones << " liberaciones (se liberan juntas)" << endl;

	// 3) si el buffer se agota con null_memory_resource se lanza bad_alloc
	array<std::byte, 64> chico;
	pmr::monotonic_buffer_resource corto(chico.data(), chico.size(), pmr::null_memory_resource());
	try {
		pmr::vector<int> z(&corto);
		for (int i = 0; i < 1000; i++) z.push_back(i);
	} catch (const bad_alloc &){
		cout << "Buffer agotado: bad_alloc, como se esperaba" << endl;
	}
	return 0;
}

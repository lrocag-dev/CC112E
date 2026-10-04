#include <iostream>
#include <memory>
#include <new>
#include <string>
#include <utility>
using namespace std;
struct Dato {
	string nombre;
	int valor;
	Dato(string n, int v) : nombre(std::move(n)), valor(v){ cout << "  [+] " << nombre << endl; }
	~Dato(){ cout << "  [-] " << nombre << endl; }
};
// Un vector minimo: separa RESERVAR memoria de CONSTRUIR objetos (como hace std::vector)
template <typename T>
class MiVector {
	T *datos = nullptr;
	size_t n = 0, cap = 0;
	void reservar(size_t nueva){
		T *nuevo = static_cast<T *>(::operator new(nueva * sizeof(T), align_val_t(alignof(T))));
		for (size_t i = 0; i < n; i++){
			construct_at(nuevo + i, std::move(datos[i]));       // construir en memoria cruda
			destroy_at(datos + i);                               // destruir el original
		}
		::operator delete(datos, align_val_t(alignof(T)));
		datos = nuevo;
		cap = nueva;
	}
public:
	MiVector() = default;
	MiVector(const MiVector &) = delete;
	MiVector &operator=(const MiVector &) = delete;
	~MiVector(){
		destroy(datos, datos + n);                               // C++17: destruye un rango
		::operator delete(datos, align_val_t(alignof(T)));
	}
	template <typename... Args>
	T &emplace_back(Args &&...args){
		if (n == cap) reservar(cap ? cap * 2 : 1);
		return *construct_at(datos + n++, std::forward<Args>(args)...);
	}
	void pop_back(){ destroy_at(datos + --n); }
	T &operator[](size_t i){ return datos[i]; }
	size_t size() const { return n; }
	size_t capacity() const { return cap; }
};
int main(){
	cout << "Insertando:" << endl;
	MiVector<Dato> v;
	v.emplace_back("A", 1);
	v.emplace_back("B", 2);
	v.emplace_back("C", 3);                  // fuerza reubicacion
	cout << "size=" << v.size() << " capacity=" << v.capacity() << endl;
	cout << "pop_back:" << endl;
	v.pop_back();
	cout << "v[1] = " << v[1].nombre << "/" << v[1].valor << endl;
	cout << "Fin de main (se destruyen los restantes):" << endl;
	return 0;
}

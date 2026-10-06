#include <iostream>
#include <vector>
#include <span>
#include <algorithm>
using namespace std;
void mostrarCap(const char *et, const vector<int> &v){
	cout << et << ": size=" << v.size() << " capacity=" << v.capacity() << endl;
}
// matriz contigua con vector: m(i, j) -> datos[i*c + j]; las filas se exponen como span
class MatrizV {
	size_t f, c;
	vector<int> d;
public:
	MatrizV(size_t f, size_t c) : f(f), c(c), d(f * c) {}
	int &operator()(size_t i, size_t j){ return d[i * c + j]; }
	span<int> fila(size_t i){ return span<int>(d).subspan(i * c, c); }
	size_t nf() const { return f; }
};
int main(){
	vector<int> v;
	size_t ultima = 0;
	for (int i = 0; i < 40; i++){
		v.push_back(i);
		if (v.capacity() != ultima){ ultima = v.capacity(); cout << "tamano " << v.size() << " -> capacidad " << ultima << endl; }
	}
	vector<int> w;
	w.reserve(100);                       // una sola reserva
	mostrarCap("reserve(100)", w);
	for (int i = 0; i < 10; i++) w.push_back(i);
	w.shrink_to_fit();                    // devuelve el exceso
	mostrarCap("shrink_to_fit", w);

	// std::erase / std::erase_if (C++20): borrar elementos sin el idioma erase-remove
	vector<int> x = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	auto n1 = erase_if(x, [](int e){ return e % 3 == 0; });
	auto n2 = erase(x, 7);
	cout << "Eliminados " << n1 << " multiplos de 3 y " << n2 << " siete; quedan:";
	for (int e : x) cout << " " << e;
	cout << endl;

	vector<vector<int>> irregular(4);                  // matriz irregular
	for (size_t i = 0; i < irregular.size(); i++) irregular[i].assign(i + 1, static_cast<int>(i));
	cout << "Filas de la irregular:";
	for (const auto &r : irregular) cout << " " << r.size();
	cout << endl;

	MatrizV m(3, 4);
	for (size_t i = 0; i < 3; i++) for (size_t j = 0; j < 4; j++) m(i, j) = static_cast<int>(i * 10 + j);
	ranges::reverse(m.fila(1));                        // opera sobre una fila como rango
	for (size_t i = 0; i < 3; i++){
		for (int e : m.fila(i)) cout << e << "\t";
		cout << endl;
	}
	return 0;
}

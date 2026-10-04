#include <iostream>
#include <optional>
#include <string>
#include <vector>
using namespace std;
struct Libro {
	int id;
	string titulo;
	int stock;
};
vector<Libro> catalogo = {
	{101, "Algoritmos", 3}, {102, "C++ Primer", 0}, {103, "Calculo I", 5}
};
// optional: "puede no haber resultado" sin usar punteros nulos ni codigos magicos
optional<Libro> buscar(int id){
	for (const auto &l : catalogo)
		if (l.id == id) return l;
	return nullopt;
}
Libro *buscarRef(int id){
	for (auto &l : catalogo)
		if (l.id == id) return &l;
	return nullptr;
}
optional<int> prestar(int id){
	// if con inicializador (C++17): 'l' solo existe dentro del if/else
	if (auto *l = buscarRef(id); l && l->stock > 0){
		l->stock--;
		return l->stock;                    // stock restante
	}
	return nullopt;
}
int main(){
	for (int id : {101, 102, 999}){
		if (auto l = buscar(id))
			cout << id << ": " << l->titulo << " (stock " << l->stock << ")" << endl;
		else
			cout << id << ": no existe" << endl;
	}
	for (int id : {101, 101, 101, 101, 102, 999}){
		if (auto resto = prestar(id))
			cout << "Prestamo de " << id << " OK, quedan " << *resto << endl;
		else
			cout << "Prestamo de " << id << " rechazado" << endl;
	}
	cout << buscar(103).value_or(Libro{0, "N/A", 0}).titulo << endl;
	cout << buscar(555).value_or(Libro{0, "N/A", 0}).titulo << endl;
	return 0;
}

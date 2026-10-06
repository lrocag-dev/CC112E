#include <iostream>
#include <memory>
#include <span>
#include <cstdio>
#include <string>
using namespace std;
// Lista enlazada simple cuyos nodos pertenecen a unique_ptr: se libera sola
struct Nodo {
	int dato;
	unique_ptr<Nodo> sig;
	Nodo(int d) : dato(d) {}
};
class Lista {
	unique_ptr<Nodo> cabeza;
	size_t n = 0;
public:
	void insertarInicio(int d){
		auto nuevo = make_unique<Nodo>(d);
		nuevo->sig = move(cabeza);
		cabeza = move(nuevo);
		n++;
	}
	void mostrar() const {
		for (const Nodo *p = cabeza.get(); p; p = p->sig.get())
			cout << p->dato << " -> ";
		cout << "null (" << n << " nodos)" << endl;
	}
	void invertir(){
		unique_ptr<Nodo> prev;
		while (cabeza){
			unique_ptr<Nodo> sig = move(cabeza->sig);
			cabeza->sig = move(prev);
			prev = move(cabeza);
			cabeza = move(sig);
		}
		cabeza = move(prev);
	}
	// ~Lista() por defecto: libera nodo a nodo (recursivo; suficiente para listas cortas)
};
int main(){
	// C++20: make_unique_for_overwrite no inicializa (mas rapido si luego se llena)
	size_t n = 6;
	auto v = make_unique_for_overwrite<int[]>(n);
	for (size_t i = 0; i < n; i++) v[i] = static_cast<int>(i * i);
	span<const int> vista(v.get(), n);
	for (int x : vista) cout << x << " ";
	cout << endl;

	// unique_ptr con eliminador personalizado: cierra el archivo automaticamente
	auto cerrar = [](FILE *f){ if (f){ fclose(f); cout << "[archivo cerrado]" << endl; } };
	unique_ptr<FILE, decltype(cerrar)> f(fopen("/tmp/prueba_ptr.txt", "w"), cerrar);
	if (f) fputs("hola\n", f.get());

	Lista l;
	for (int i = 1; i <= 5; i++) l.insertarInicio(i);
	l.mostrar();
	l.invertir();
	l.mostrar();
	return 0;
}

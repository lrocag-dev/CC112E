#include <iostream>
using namespace std;
struct Nodo {
	int dato;
	Nodo *sig;
};
void insertarFinal(Nodo *&cabeza, int x){
	Nodo *nuevo = new Nodo{x, nullptr};
	if (!cabeza){ cabeza = nuevo; return; }
	Nodo *p = cabeza;
	while (p->sig) p = p->sig;
	p->sig = nuevo;
}
void insertarInicio(Nodo *&cabeza, int x){ cabeza = new Nodo{x, cabeza}; }
bool eliminar(Nodo *&cabeza, int x){                // elimina la primera aparicion
	Nodo **pp = &cabeza;                            // puntero al enlace que apunta al nodo actual
	while (*pp && (*pp)->dato != x) pp = &(*pp)->sig;
	if (!*pp) return false;
	Nodo *borrar = *pp;
	*pp = borrar->sig;
	delete borrar;
	return true;
}
void invertir(Nodo *&cabeza){
	Nodo *prev = nullptr, *p = cabeza;
	while (p){
		Nodo *sig = p->sig;
		p->sig = prev;
		prev = p;
		p = sig;
	}
	cabeza = prev;
}
void mostrar(const Nodo *p){
	for (; p; p = p->sig) cout << p->dato << " -> ";
	cout << "null" << endl;
}
void liberar(Nodo *&cabeza){
	while (cabeza){
		Nodo *sig = cabeza->sig;
		delete cabeza;
		cabeza = sig;
	}
}
int main(){
	Nodo *l = nullptr;
	for (int i = 1; i <= 5; i++) insertarFinal(l, i * 10);
	insertarInicio(l, 5);
	mostrar(l);
	cout << "Eliminar 30: " << boolalpha << eliminar(l, 30) << ", eliminar 99: " << eliminar(l, 99) << endl;
	eliminar(l, 5);                                  // eliminar la cabeza
	mostrar(l);
	invertir(l);
	mostrar(l);
	liberar(l);
	cout << "Lista liberada: " << (l == nullptr) << endl;
	return 0;
}

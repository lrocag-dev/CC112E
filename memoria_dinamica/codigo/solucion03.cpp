#include <iostream>
using namespace std;
// Arreglo que crece: al llenarse duplica su capacidad
struct ArregloDinamico {
	int *datos;
	int tamano;
	int capacidad;
};
void iniciar(ArregloDinamico &v, int capacidadInicial = 2){
	v.datos = new int[capacidadInicial];
	v.tamano = 0;
	v.capacidad = capacidadInicial;
}
void agregar(ArregloDinamico &v, int x){
	if (v.tamano == v.capacidad){
		int nueva = v.capacidad * 2;
		int *nuevo = new int[nueva];
		for (int i = 0; i < v.tamano; i++) nuevo[i] = v.datos[i];
		delete[] v.datos;
		v.datos = nuevo;
		v.capacidad = nueva;
		cout << "  [crece a capacidad " << nueva << "]" << endl;
	}
	v.datos[v.tamano++] = x;
}
void liberar(ArregloDinamico &v){
	delete[] v.datos;
	v.datos = nullptr;
	v.tamano = v.capacidad = 0;
}
int main(){
	ArregloDinamico v;
	iniciar(v);
	int x;
	cout << "Ingrese enteros (0 para terminar):" << endl;
	while (cin >> x && x != 0) agregar(v, x);
	cout << "Tamano " << v.tamano << ", capacidad " << v.capacidad << endl;
	for (int i = 0; i < v.tamano; i++) cout << v.datos[i] << " ";
	cout << endl;
	liberar(v);
	return 0;
}

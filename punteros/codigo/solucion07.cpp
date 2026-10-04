#include <iostream>
using namespace std;
int main(){
	const int N = 6;
	int datos[N] = {42, 7, 19, 3, 88, 25};
	int *ptr[N];                      // arreglo de punteros
	for (int i = 0; i < N; i++)
		ptr[i] = &datos[i];
	// burbuja sobre los PUNTEROS: los datos no se mueven
	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < N - 1 - i; j++)
			if (*ptr[j] > *ptr[j + 1]){
				int *aux = ptr[j];
				ptr[j] = ptr[j + 1];
				ptr[j + 1] = aux;
			}
	cout << "Datos originales: ";
	for (int i = 0; i < N; i++) cout << datos[i] << " ";
	cout << endl << "Orden ascendente via punteros: ";
	for (int i = 0; i < N; i++) cout << *ptr[i] << " ";
	cout << endl << "Posicion original de cada uno: ";
	for (int i = 0; i < N; i++) cout << ptr[i] - datos << " ";
	cout << endl;
	return 0;
}

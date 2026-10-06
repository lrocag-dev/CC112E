#include <iostream>
using namespace std;
int main(){
	// variable simple en el heap
	int *p = new int(25);
	cout << "Valor: " << *p << ", direccion en el heap: " << p << endl;
	*p += 5;
	cout << "Tras sumar 5: " << *p << endl;
	delete p;                          // liberar con delete
	p = nullptr;                       // evita un puntero colgante

	// arreglo cuyo tamano se conoce solo en ejecucion
	int n;
	cout << "Cantidad de notas: ";
	cin >> n;
	double *notas = new double[n];     // liberar con delete[]
	double suma = 0;
	for (int i = 0; i < n; i++){
		cout << "Nota " << i + 1 << ": ";
		cin >> notas[i];
		suma += notas[i];
	}
	cout << "Promedio: " << suma / n << endl;
	delete[] notas;
	notas = nullptr;
	return 0;
}

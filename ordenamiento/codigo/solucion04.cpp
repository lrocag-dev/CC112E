#include <iostream>
using namespace std;
void insercion(int *a, int n){
	for (int i = 1; i < n; i++){
		int x = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > x){      // desplazar los mayores
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}
// inserta x en un arreglo ya ordenado de tamano n (debe haber espacio)
void insertarOrdenado(int *a, int &n, int x){
	int j = n - 1;
	while (j >= 0 && a[j] > x){
		a[j + 1] = a[j];
		j--;
	}
	a[j + 1] = x;
	n++;
}
void mostrar(const int *a, int n){ for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl; }
int main(){
	int a[20] = {9, 5, 1, 4, 3, 8, 2};
	int n = 7;
	insercion(a, n);
	mostrar(a, n);
	int x;
	cout << "Valor a insertar en orden: ";
	cin >> x;
	insertarOrdenado(a, n, x);
	mostrar(a, n);
	return 0;
}

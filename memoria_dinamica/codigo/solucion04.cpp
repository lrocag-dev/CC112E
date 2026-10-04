#include <iostream>
using namespace std;
// La funcion reserva; el LLAMADOR es responsable de liberar
int *filtrarPares(const int *a, int n, int &cantidad){
	cantidad = 0;
	for (int i = 0; i < n; i++) if (a[i] % 2 == 0) cantidad++;
	int *r = new int[cantidad];
	int k = 0;
	for (int i = 0; i < n; i++) if (a[i] % 2 == 0) r[k++] = a[i];
	return r;
}
int *rango(int ini, int fin, int &n){            // ini..fin
	n = fin - ini + 1;
	int *r = new int[n];
	for (int i = 0; i < n; i++) r[i] = ini + i;
	return r;
}
// ERROR tipico: devolver la direccion de un arreglo local (queda colgante)
// int *mal(){ int a[3] = {1,2,3}; return a; }
int main(){
	int n;
	int *a = rango(1, 15, n);
	int k;
	int *pares = filtrarPares(a, n, k);
	cout << k << " pares: ";
	for (int i = 0; i < k; i++) cout << pares[i] << " ";
	cout << endl;
	delete[] a;
	delete[] pares;
	return 0;
}

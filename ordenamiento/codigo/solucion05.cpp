#include <iostream>
using namespace std;
int binariaIter(const int *a, int n, int clave, int &pasos){
	int ini = 0, fin = n - 1;
	pasos = 0;
	while (ini <= fin){
		pasos++;
		int mid = ini + (fin - ini) / 2;          // evita desbordamiento de ini+fin
		if (a[mid] == clave) return mid;
		if (a[mid] < clave) ini = mid + 1;
		else fin = mid - 1;
	}
	return -1;
}
int binariaRec(const int *a, int ini, int fin, int clave){
	if (ini > fin) return -1;
	int mid = ini + (fin - ini) / 2;
	if (a[mid] == clave) return mid;
	return a[mid] < clave ? binariaRec(a, mid + 1, fin, clave) : binariaRec(a, ini, mid - 1, clave);
}
// primera aparicion cuando hay repetidos (lower bound)
int primera(const int *a, int n, int clave){
	int ini = 0, fin = n;
	while (ini < fin){
		int mid = ini + (fin - ini) / 2;
		if (a[mid] < clave) ini = mid + 1;
		else fin = mid;
	}
	return (ini < n && a[ini] == clave) ? ini : -1;
}
int main(){
	int a[] = {1, 3, 3, 3, 5, 8, 8, 13, 21, 34, 55, 89};
	int n = 12, clave, pasos;
	cout << "Clave: ";
	cin >> clave;
	int p = binariaIter(a, n, clave, pasos);
	cout << "Iterativa: " << p << " (" << pasos << " pasos)" << endl;
	cout << "Recursiva: " << binariaRec(a, 0, n - 1, clave) << endl;
	cout << "Primera aparicion: " << primera(a, n, clave) << endl;
	cout << "Con 1 000 000 elementos: maximo " << 20 << " pasos (log2)" << endl;
	return 0;
}

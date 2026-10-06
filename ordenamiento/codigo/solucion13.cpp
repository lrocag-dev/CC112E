#include <iostream>
using namespace std;
// raiz cuadrada entera por busqueda binaria sobre la RESPUESTA
long raizEntera(long n){
	long ini = 0, fin = n, res = 0;
	while (ini <= fin){
		long mid = ini + (fin - ini) / 2;
		if (mid <= n / (mid == 0 ? 1 : mid)){ res = mid; ini = mid + 1; }
		else fin = mid - 1;
	}
	return res;
}
// busqueda en arreglo ordenado y ROTADO, sin duplicados: O(log n)
int buscarRotado(const int *a, int n, int clave){
	int ini = 0, fin = n - 1;
	while (ini <= fin){
		int mid = ini + (fin - ini) / 2;
		if (a[mid] == clave) return mid;
		if (a[ini] <= a[mid]){                         // mitad izquierda ordenada
			if (a[ini] <= clave && clave < a[mid]) fin = mid - 1;
			else ini = mid + 1;
		} else {                                       // mitad derecha ordenada
			if (a[mid] < clave && clave <= a[fin]) ini = mid + 1;
			else fin = mid - 1;
		}
	}
	return -1;
}
int indiceRotacion(const int *a, int n){               // posicion del minimo
	int ini = 0, fin = n - 1;
	while (ini < fin){
		int mid = ini + (fin - ini) / 2;
		if (a[mid] > a[fin]) ini = mid + 1;
		else fin = mid;
	}
	return ini;
}
int main(){
	for (long n : {0L, 1L, 15L, 16L, 99L, 1000000L})
		cout << "raiz(" << n << ") = " << raizEntera(n) << endl;
	int a[] = {15, 18, 22, 30, 2, 5, 8, 11};
	cout << "Rotacion en el indice " << indiceRotacion(a, 8) << endl;
	for (int c : {5, 30, 11, 15, 9})
		cout << "buscar " << c << " -> " << buscarRotado(a, 8, c) << endl;
	return 0;
}

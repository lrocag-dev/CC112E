#include <iostream>
using namespace std;
// Ordenamiento por conteo: O(n + k), estable, para enteros en [0, k)
void countingSort(const int *a, int n, int *salida, int k){
	int cuenta[100] = {0};
	for (int i = 0; i < n; i++) cuenta[a[i]]++;
	for (int v = 1; v < k; v++) cuenta[v] += cuenta[v - 1];     // posiciones finales
	for (int i = n - 1; i >= 0; i--)                             // de atras para atras: estable
		salida[--cuenta[a[i]]] = a[i];
}
// ordenar por frecuencia descendente (empate: por orden de aparicion)
void porFrecuencia(const int *a, int n){
	int frec[100] = {0}, primero[100];
	for (int v = 0; v < 100; v++) primero[v] = -1;
	for (int i = 0; i < n; i++){
		frec[a[i]]++;
		if (primero[a[i]] < 0) primero[a[i]] = i;
	}
	int valores[100], m = 0;
	for (int v = 0; v < 100; v++) if (frec[v]) valores[m++] = v;
	for (int i = 1; i < m; i++){                                  // insercion sobre los valores distintos
		int x = valores[i], j = i - 1;
		while (j >= 0 && (frec[valores[j]] < frec[x] ||
		       (frec[valores[j]] == frec[x] && primero[valores[j]] > primero[x]))){
			valores[j + 1] = valores[j];
			j--;
		}
		valores[j + 1] = x;
	}
	for (int i = 0; i < m; i++)
		for (int r = 0; r < frec[valores[i]]; r++) cout << valores[i] << " ";
	cout << endl;
}
int main(){
	int a[] = {4, 2, 2, 8, 3, 3, 1, 4, 3, 9, 2, 3};
	int n = 12, s[12];
	countingSort(a, n, s, 10);
	for (int x : s) cout << x << " ";
	cout << endl << "Por frecuencia: ";
	porFrecuencia(a, n);
	return 0;
}

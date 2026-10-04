#include <iostream>
using namespace std;
int particion(int *a, int ini, int fin){
	int pivote = a[fin], i = ini - 1;
	for (int j = ini; j < fin; j++)
		if (a[j] <= pivote) swap(a[++i], a[j]);
	swap(a[i + 1], a[fin]);
	return i + 1;
}
// k-esimo menor (k desde 0) en O(n) promedio: solo se explora un lado
int quickSelect(int *a, int ini, int fin, int k){
	if (ini == fin) return a[ini];
	int p = particion(a, ini, fin);
	if (k == p) return a[p];
	return k < p ? quickSelect(a, ini, p - 1, k) : quickSelect(a, p + 1, fin, k);
}
int main(){
	int a[] = {7, 10, 4, 3, 20, 15, 1, 12, 9};
	int n = 9, k;
	cout << "k (1 = menor): ";
	cin >> k;
	int copia[9];
	for (int i = 0; i < n; i++) copia[i] = a[i];
	cout << k << "-esimo menor: " << quickSelect(copia, 0, n - 1, k - 1) << endl;
	for (int i = 0; i < n; i++) copia[i] = a[i];
	cout << "Mediana: " << quickSelect(copia, 0, n - 1, n / 2) << endl;
	for (int i = 0; i < n; i++) copia[i] = a[i];
	cout << "Mayor: " << quickSelect(copia, 0, n - 1, n - 1) << endl;
	return 0;
}

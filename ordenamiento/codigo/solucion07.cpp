#include <iostream>
using namespace std;
long comparaciones = 0;
int particion(int *a, int ini, int fin){            // Lomuto: pivote = ultimo
	int pivote = a[fin];
	int i = ini - 1;
	for (int j = ini; j < fin; j++){
		comparaciones++;
		if (a[j] <= pivote){
			i++;
			int aux = a[i]; a[i] = a[j]; a[j] = aux;
		}
	}
	int aux = a[i + 1]; a[i + 1] = a[fin]; a[fin] = aux;
	return i + 1;
}
void quickSort(int *a, int ini, int fin){
	if (ini >= fin) return;
	int p = particion(a, ini, fin);
	quickSort(a, ini, p - 1);
	quickSort(a, p + 1, fin);
}
int main(){
	int a[] = {10, 80, 30, 90, 40, 50, 70, 20, 60};
	int n = 9;
	quickSort(a, 0, n - 1);
	for (int x : a) cout << x << " ";
	cout << endl << "Comparaciones: " << comparaciones << endl;
	int b[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};      // peor caso con pivote = ultimo
	comparaciones = 0;
	quickSort(b, 0, 8);
	cout << "Ya ordenado: " << comparaciones << " comparaciones (peor caso O(n^2))" << endl;
	return 0;
}

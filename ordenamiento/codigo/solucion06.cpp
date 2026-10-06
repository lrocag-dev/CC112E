#include <iostream>
using namespace std;
void fusionar(int *a, int ini, int mid, int fin){
	int n1 = mid - ini + 1, n2 = fin - mid;
	int L[100], R[100];
	for (int i = 0; i < n1; i++) L[i] = a[ini + i];
	for (int j = 0; j < n2; j++) R[j] = a[mid + 1 + j];
	int i = 0, j = 0, k = ini;
	while (i < n1 && j < n2)
		a[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];      // <= mantiene la estabilidad
	while (i < n1) a[k++] = L[i++];
	while (j < n2) a[k++] = R[j++];
}
void mergeSort(int *a, int ini, int fin){
	if (ini >= fin) return;
	int mid = ini + (fin - ini) / 2;
	mergeSort(a, ini, mid);
	mergeSort(a, mid + 1, fin);
	fusionar(a, ini, mid, fin);
}
int main(){
	int a[] = {38, 27, 43, 3, 9, 82, 10, 3, 55, 1};
	int n = 10;
	mergeSort(a, 0, n - 1);
	for (int x : a) cout << x << " ";
	cout << endl;
	return 0;
}

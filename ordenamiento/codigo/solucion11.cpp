#include <iostream>
using namespace std;
typedef long long ll;
// cuenta pares (i<j) con a[i] > a[j] mientras ordena: O(n log n)
ll fusionarContando(int *a, int *tmp, int ini, int mid, int fin){
	ll inv = 0;
	int i = ini, j = mid + 1, k = ini;
	while (i <= mid && j <= fin){
		if (a[i] <= a[j]) tmp[k++] = a[i++];
		else {
			tmp[k++] = a[j++];
			inv += mid - i + 1;               // a[i..mid] son todos mayores que a[j]
		}
	}
	while (i <= mid) tmp[k++] = a[i++];
	while (j <= fin) tmp[k++] = a[j++];
	for (int x = ini; x <= fin; x++) a[x] = tmp[x];
	return inv;
}
ll contar(int *a, int *tmp, int ini, int fin){
	if (ini >= fin) return 0;
	int mid = ini + (fin - ini) / 2;
	return contar(a, tmp, ini, mid) + contar(a, tmp, mid + 1, fin) + fusionarContando(a, tmp, ini, mid, fin);
}
ll fuerzaBruta(const int *a, int n){
	ll c = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j]) c++;
	return c;
}
int main(){
	int a[] = {8, 4, 2, 1, 7, 3, 6, 5};
	int n = 8, tmp[8];
	cout << "Inversiones (fuerza bruta): " << fuerzaBruta(a, n) << endl;
	cout << "Inversiones (merge sort):   " << contar(a, tmp, 0, n - 1) << endl;
	for (int x : a) cout << x << " ";
	cout << endl;
	int b[] = {5, 4, 3, 2, 1}, t2[5];
	cout << "Inverso de 5 elementos: " << contar(b, t2, 0, 4) << " (maximo n(n-1)/2 = 10)" << endl;
	return 0;
}

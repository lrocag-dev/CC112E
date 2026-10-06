#include <iostream>
using namespace std;
int suma(const int *a, int n){
	if (n == 0) return 0;
	return *a + suma(a + 1, n - 1);
}
int maximo(const int *a, int n){
	if (n == 1) return *a;
	int m = maximo(a + 1, n - 1);
	return *a > m ? *a : m;
}
int buscar(const int *a, int n, int clave){        // posicion o -1
	if (n == 0) return -1;
	if (*a == clave) return 0;
	int r = buscar(a + 1, n - 1, clave);
	return r == -1 ? -1 : r + 1;
}
void invertir(int *a, int n){
	if (n < 2) return;
	int aux = a[0];
	a[0] = a[n - 1];
	a[n - 1] = aux;
	invertir(a + 1, n - 2);
}
int main(){
	int a[] = {4, 9, 2, 7, 5, 1};
	int n = 6;
	cout << "Suma: " << suma(a, n) << endl;
	cout << "Maximo: " << maximo(a, n) << endl;
	cout << "Posicion de 7: " << buscar(a, n, 7) << ", de 8: " << buscar(a, n, 8) << endl;
	invertir(a, n);
	for (int x : a) cout << x << " ";
	cout << endl;
	return 0;
}

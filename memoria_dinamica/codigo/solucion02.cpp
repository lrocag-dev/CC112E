#include <iostream>
using namespace std;
void leer(int *a, int n){
	for (int *p = a; p < a + n; p++){ cout << "  dato: "; cin >> *p; }
}
void maxMin(const int *a, int n, int &mx, int &mn){
	mx = mn = a[0];
	for (int i = 1; i < n; i++){
		if (a[i] > mx) mx = a[i];
		if (a[i] < mn) mn = a[i];
	}
}
int main(){
	int n;
	cout << "n: ";
	cin >> n;
	if (n <= 0){ cout << "n invalido" << endl; return 1; }
	int *a = new int[n]();            // () inicializa en cero
	leer(a, n);
	int mx, mn;
	maxMin(a, n, mx, mn);
	cout << "Maximo " << mx << ", minimo " << mn << endl;
	cout << "Arreglo: ";
	for (int i = 0; i < n; i++) cout << a[i] << " ";
	cout << endl;
	delete[] a;                       // new[] -> delete[]  (nunca delete a)
	return 0;
}

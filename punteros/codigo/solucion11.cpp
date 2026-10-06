#include <iostream>
using namespace std;
void invertir(int *ini, int *fin){
	while (ini < fin){
		int aux = *ini; *ini = *fin; *fin = aux;
		ini++; fin--;
	}
}
// rotacion a la izquierda en O(n) y O(1) de memoria (algoritmo de las tres inversiones)
void rotarIzquierda(int *a, int n, int k){
	if (n == 0) return;
	k %= n;
	if (k < 0) k += n;                // k negativo rota a la derecha
	invertir(a, a + k - 1);
	invertir(a + k, a + n - 1);
	invertir(a, a + n - 1);
}
int main(){
	int a[100], n, k;
	cout << "n y k: ";
	cin >> n >> k;
	for (int *p = a; p < a + n; p++) cin >> *p;
	rotarIzquierda(a, n, k);
	for (int *p = a; p < a + n; p++) cout << *p << " ";
	cout << endl;
	return 0;
}

#include <iostream>
using namespace std;
int sol = 0;
// incluir o no incluir cada elemento
bool existeSubconjunto(const int *a, int n, int objetivo){
	if (objetivo == 0) return true;
	if (n == 0 || objetivo < 0) return false;
	return existeSubconjunto(a + 1, n - 1, objetivo - a[0])      // incluye a[0]
	    || existeSubconjunto(a + 1, n - 1, objetivo);            // no lo incluye
}
int contarSubconjuntos(const int *a, int n, int objetivo){
	if (n == 0) return objetivo == 0 ? 1 : 0;
	return contarSubconjuntos(a + 1, n - 1, objetivo - a[0])
	     + contarSubconjuntos(a + 1, n - 1, objetivo);
}
void mostrar(const int *a, int n, int objetivo, int *elegidos, int k){
	if (objetivo == 0){
		cout << "{ ";
		for (int i = 0; i < k; i++) cout << elegidos[i] << " ";
		cout << "}" << endl;
		return;
	}
	if (n == 0) return;
	elegidos[k] = a[0];
	mostrar(a + 1, n - 1, objetivo - a[0], elegidos, k + 1);
	mostrar(a + 1, n - 1, objetivo, elegidos, k);
}
int main(){
	int a[] = {3, 34, 4, 12, 5, 2};
	int n = 6, objetivo;
	cout << "Objetivo: ";
	cin >> objetivo;
	cout << (existeSubconjunto(a, n, objetivo) ? "Existe" : "No existe") << endl;
	cout << "Cantidad de subconjuntos: " << contarSubconjuntos(a, n, objetivo) << endl;
	int buf[10];
	mostrar(a, n, objetivo, buf, 0);
	return 0;
}

#include <iostream>
using namespace std;
// ascendente = true; descendente = false
void seleccion(int *a, int n, bool ascendente, long &intercambios){
	intercambios = 0;
	for (int i = 0; i < n - 1; i++){
		int k = i;                                        // posicion del menor (o mayor)
		for (int j = i + 1; j < n; j++)
			if (ascendente ? a[j] < a[k] : a[j] > a[k]) k = j;
		if (k != i){
			int aux = a[i]; a[i] = a[k]; a[k] = aux;
			intercambios++;
		}
	}
}
int main(){
	int a[] = {64, 25, 12, 22, 11, 90, 3};
	int n = 7;
	long inter;
	seleccion(a, n, true, inter);
	cout << "Ascendente:  ";
	for (int x : a) cout << x << " ";
	cout << "(" << inter << " intercambios)" << endl;
	seleccion(a, n, false, inter);
	cout << "Descendente: ";
	for (int x : a) cout << x << " ";
	cout << "(" << inter << " intercambios)" << endl;
	return 0;
}

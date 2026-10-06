#include <iostream>
using namespace std;
// parametros de salida mediante punteros
void extremos(const int *a, int n, int *maximo, int *minimo, int *posMax, int *posMin){
	*maximo = *minimo = *a;
	*posMax = *posMin = 0;
	for (int i = 1; i < n; i++){
		if (*(a + i) > *maximo){ *maximo = *(a + i); *posMax = i; }
		if (*(a + i) < *minimo){ *minimo = *(a + i); *posMin = i; }
	}
}
int main(){
	int a[100], n;
	cout << "n: ";
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int mx, mn, pmx, pmn;
	extremos(a, n, &mx, &mn, &pmx, &pmn);
	cout << "Maximo: " << mx << " en la posicion " << pmx << endl;
	cout << "Minimo: " << mn << " en la posicion " << pmn << endl;
	return 0;
}

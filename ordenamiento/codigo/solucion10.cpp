#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
struct Conteo { long comp = 0, mov = 0; };
void burbuja(int *a, int n, Conteo &c){
	for (int i = 0; i < n - 1; i++){
		bool cambio = false;
		for (int j = 0; j < n - 1 - i; j++){
			c.comp++;
			if (a[j] > a[j + 1]){ swap(a[j], a[j + 1]); c.mov++; cambio = true; }
		}
		if (!cambio) break;
	}
}
void seleccion(int *a, int n, Conteo &c){
	for (int i = 0; i < n - 1; i++){
		int k = i;
		for (int j = i + 1; j < n; j++){ c.comp++; if (a[j] < a[k]) k = j; }
		if (k != i){ swap(a[i], a[k]); c.mov++; }
	}
}
void insercion(int *a, int n, Conteo &c){
	for (int i = 1; i < n; i++){
		int x = a[i], j = i - 1;
		while (j >= 0){
			c.comp++;
			if (a[j] <= x) break;
			a[j + 1] = a[j]; c.mov++; j--;
		}
		a[j + 1] = x;
	}
}
void generar(int *a, int n, int tipo){          // 0 aleatorio, 1 ordenado, 2 inverso
	srand(42);
	for (int i = 0; i < n; i++)
		a[i] = tipo == 0 ? rand() % 1000 : tipo == 1 ? i : n - i;
}
int main(){
	const int n = 200;
	const char *tipos[] = {"Aleatorio", "Ordenado", "Inverso"};
	cout << "n = " << n << "   (comparaciones / movimientos)" << endl;
	cout << left << setw(11) << "Entrada" << setw(20) << "Burbuja" << setw(20) << "Seleccion" << "Insercion" << endl;
	for (int t = 0; t < 3; t++){
		cout << left << setw(11) << tipos[t];
		void (*alg[])(int *, int, Conteo &) = {burbuja, seleccion, insercion};
		for (auto f : alg){
			int a[n];
			generar(a, n, t);
			Conteo c;
			f(a, n, c);
			cout << left << setw(20) << (to_string(c.comp) + " / " + to_string(c.mov));
		}
		cout << endl;
	}
	return 0;
}

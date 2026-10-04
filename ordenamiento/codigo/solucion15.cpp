#include <iostream>
#include <cstdlib>
using namespace std;
long comp = 0;
const int UMBRAL = 8;                      // por debajo de este tamano conviene insercion
void insercion(int *a, int ini, int fin){
	for (int i = ini + 1; i <= fin; i++){
		int x = a[i], j = i - 1;
		while (j >= ini){ comp++; if (a[j] <= x) break; a[j + 1] = a[j]; j--; }
		a[j + 1] = x;
	}
}
int medianaDeTres(int *a, int ini, int fin){
	int mid = ini + (fin - ini) / 2;
	if (a[mid] < a[ini]) swap(a[mid], a[ini]);
	if (a[fin] < a[ini]) swap(a[fin], a[ini]);
	if (a[fin] < a[mid]) swap(a[fin], a[mid]);
	swap(a[mid], a[fin - 1]);              // pivote queda en fin-1
	return a[fin - 1];
}
void quickHibrido(int *a, int ini, int fin){
	if (fin - ini + 1 <= UMBRAL){ insercion(a, ini, fin); return; }
	int p = medianaDeTres(a, ini, fin);
	int i = ini, j = fin - 1;
	for (;;){
		while (comp++, a[++i] < p) ;
		while (comp++, a[--j] > p) ;
		if (i >= j) break;
		swap(a[i], a[j]);
	}
	swap(a[i], a[fin - 1]);
	quickHibrido(a, ini, i - 1);
	quickHibrido(a, i + 1, fin);
}
// quicksort simple (pivote = ultimo) para comparar
void quickSimple(int *a, int ini, int fin){
	if (ini >= fin) return;
	int p = a[fin], i = ini - 1;
	for (int j = ini; j < fin; j++){ comp++; if (a[j] <= p) swap(a[++i], a[j]); }
	swap(a[i + 1], a[fin]);
	quickSimple(a, ini, i);
	quickSimple(a, i + 2, fin);
}
int main(){
	const int n = 2000;
	static int a[n], b[n];
	for (int tipo = 0; tipo < 2; tipo++){
		srand(7);
		for (int i = 0; i < n; i++) a[i] = b[i] = tipo == 0 ? rand() % 10000 : i;   // aleatorio / ya ordenado
		comp = 0; quickSimple(a, 0, n - 1); long c1 = comp;
		comp = 0; quickHibrido(b, 0, n - 1); long c2 = comp;
		bool ok = true;
		for (int i = 1; i < n; i++) if (b[i - 1] > b[i]) ok = false;
		cout << (tipo == 0 ? "Aleatorio:  " : "Ya ordenado: ") << "simple=" << c1 << " comparaciones, hibrido="
		     << c2 << (ok ? " (correcto)" : " (ERROR)") << endl;
	}
	return 0;
}

#include <iostream>
using namespace std;
struct Conteo { long comparaciones = 0, intercambios = 0; };
void burbuja(int *a, int n, Conteo &c, bool optimizado){
	for (int i = 0; i < n - 1; i++){
		bool huboCambio = false;
		for (int j = 0; j < n - 1 - i; j++){
			c.comparaciones++;
			if (a[j] > a[j + 1]){
				int aux = a[j]; a[j] = a[j + 1]; a[j + 1] = aux;
				c.intercambios++;
				huboCambio = true;
			}
		}
		if (optimizado && !huboCambio) break;     // ya esta ordenado
	}
}
void mostrar(const int *a, int n){
	for (int i = 0; i < n; i++) cout << a[i] << " ";
	cout << endl;
}
int main(){
	int base1[] = {5, 1, 4, 2, 8, 0};
	int base2[] = {1, 2, 3, 4, 5, 6};          // ya ordenado
	for (bool opt : {false, true}){
		int a[6], b[6];
		for (int i = 0; i < 6; i++){ a[i] = base1[i]; b[i] = base2[i]; }
		Conteo c1, c2;
		burbuja(a, 6, c1, opt);
		burbuja(b, 6, c2, opt);
		cout << (opt ? "Con bandera" : "Sin bandera") << ":" << endl;
		cout << "  desordenado -> "; mostrar(a, 6);
		cout << "     " << c1.comparaciones << " comparaciones, " << c1.intercambios << " intercambios" << endl;
		cout << "  ya ordenado -> " << c2.comparaciones << " comparaciones, " << c2.intercambios << " intercambios" << endl;
	}
	return 0;
}

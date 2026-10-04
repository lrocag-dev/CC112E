#include <iostream>
using namespace std;
// primera aparicion y conteo de comparaciones; -1 si no esta
int buscar(const int *a, int n, int clave, int &comparaciones){
	comparaciones = 0;
	for (int i = 0; i < n; i++){
		comparaciones++;
		if (a[i] == clave) return i;
	}
	return -1;
}
// todas las apariciones
int buscarTodas(const int *a, int n, int clave, int *pos){
	int k = 0;
	for (int i = 0; i < n; i++)
		if (a[i] == clave) pos[k++] = i;
	return k;
}
int main(){
	int a[] = {7, 3, 9, 3, 1, 8, 3, 6};
	int n = 8, clave, comp;
	cout << "Clave: ";
	cin >> clave;
	int p = buscar(a, n, clave, comp);
	if (p >= 0) cout << "Primera aparicion en " << p << " tras " << comp << " comparaciones" << endl;
	else cout << "No esta (" << comp << " comparaciones)" << endl;
	int pos[8];
	int k = buscarTodas(a, n, clave, pos);
	cout << "Apariciones: " << k << " en posiciones:";
	for (int i = 0; i < k; i++) cout << " " << pos[i];
	cout << endl;
	return 0;
}

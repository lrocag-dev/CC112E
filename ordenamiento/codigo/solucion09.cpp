#include <iostream>
#include <cstring>
using namespace std;
const int N = 8, L = 20;
// busqueda binaria de una cadena en un arreglo ordenado alfabeticamente
int buscarNombre(char nombres[][L], int n, const char *clave){
	int ini = 0, fin = n - 1;
	while (ini <= fin){
		int mid = (ini + fin) / 2;
		int c = strcmp(nombres[mid], clave);
		if (c == 0) return mid;
		if (c < 0) ini = mid + 1;
		else fin = mid - 1;
	}
	return -1;
}
int main(){
	char nombres[N][L] = {"Rosa", "Luis", "Ana", "Pedro", "Beto", "Marta", "Zoe", "Carlos"};
	for (int i = 1; i < N; i++){                       // insercion con strcmp
		char x[L];
		strcpy(x, nombres[i]);
		int j = i - 1;
		while (j >= 0 && strcmp(nombres[j], x) > 0){
			strcpy(nombres[j + 1], nombres[j]);
			j--;
		}
		strcpy(nombres[j + 1], x);
	}
	for (int i = 0; i < N; i++) cout << nombres[i] << " ";
	cout << endl;
	char clave[L];
	cout << "Nombre a buscar: ";
	cin >> clave;
	int p = buscarNombre(nombres, N, clave);
	if (p >= 0) cout << clave << " esta en la posicion " << p << endl;
	else cout << clave << " no esta en la lista" << endl;
	return 0;
}

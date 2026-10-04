#include <iostream>
using namespace std;
int **crearMatriz(int f, int c){
	int **m = new int *[f];
	for (int i = 0; i < f; i++) m[i] = new int[c]();
	return m;
}
void liberarMatriz(int **m, int f){
	for (int i = 0; i < f; i++) delete[] m[i];     // primero las filas
	delete[] m;                                     // luego el arreglo de punteros
}
int **transpuesta(int **m, int f, int c){
	int **t = crearMatriz(c, f);
	for (int i = 0; i < f; i++)
		for (int j = 0; j < c; j++) t[j][i] = m[i][j];
	return t;
}
void mostrar(int **m, int f, int c){
	for (int i = 0; i < f; i++){
		for (int j = 0; j < c; j++) cout << m[i][j] << "\t";
		cout << endl;
	}
}
int main(){
	int f, c;
	cout << "Filas y columnas: ";
	cin >> f >> c;
	int **m = crearMatriz(f, c);
	for (int i = 0; i < f; i++)
		for (int j = 0; j < c; j++) m[i][j] = i * c + j + 1;
	mostrar(m, f, c);
	for (int i = 0; i < f; i++){
		int s = 0;
		for (int j = 0; j < c; j++) s += m[i][j];
		cout << "Suma de la fila " << i << ": " << s << endl;
	}
	int **t = transpuesta(m, f, c);
	cout << "Transpuesta:" << endl;
	mostrar(t, c, f);
	liberarMatriz(m, f);
	liberarMatriz(t, c);
	return 0;
}

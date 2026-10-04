#include <iostream>
using namespace std;
// Matriz en UN solo bloque contiguo: m[i][j] -> datos[i * columnas + j]
struct Matriz {
	int filas, columnas;
	double *datos;
};
Matriz crear(int f, int c){ return {f, c, new double[f * c]()}; }
void liberar(Matriz &m){ delete[] m.datos; m.datos = nullptr; }
double &en(Matriz &m, int i, int j){ return m.datos[i * m.columnas + j]; }
Matriz multiplicar(Matriz &a, Matriz &b){
	Matriz r = crear(a.filas, b.columnas);
	for (int i = 0; i < a.filas; i++)
		for (int j = 0; j < b.columnas; j++)
			for (int k = 0; k < a.columnas; k++)
				en(r, i, j) += en(a, i, k) * en(b, k, j);
	return r;
}
void mostrar(Matriz &m){
	for (int i = 0; i < m.filas; i++){
		for (int j = 0; j < m.columnas; j++) cout << en(m, i, j) << "\t";
		cout << endl;
	}
}
int main(){
	Matriz a = crear(2, 3), b = crear(3, 2);
	int v = 1;
	for (int i = 0; i < 2; i++) for (int j = 0; j < 3; j++) en(a, i, j) = v++;
	for (int i = 0; i < 3; i++) for (int j = 0; j < 2; j++) en(b, i, j) = v++;
	Matriz c = multiplicar(a, b);
	cout << "A x B =" << endl;
	mostrar(c);
	// ventaja: una sola reserva, una sola liberacion y mejor localidad de cache
	cout << "Direcciones consecutivas: " << &en(a, 0, 0) << " " << &en(a, 0, 1) << endl;
	liberar(a); liberar(b); liberar(c);
	return 0;
}

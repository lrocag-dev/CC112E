#include <iostream>
using namespace std;
// Matriz dispersa: se guardan solo los elementos distintos de cero
struct Elemento { int fila, col; double valor; };
struct Dispersa {
	int filas, cols;
	Elemento *e;
	int nnz;                // numero de no ceros
};
Dispersa desdeDensa(double *m, int f, int c){
	int cnt = 0;
	for (int i = 0; i < f * c; i++) if (m[i] != 0) cnt++;
	Dispersa d{f, c, new Elemento[cnt], cnt};
	int k = 0;
	for (int i = 0; i < f; i++)
		for (int j = 0; j < c; j++)
			if (m[i * c + j] != 0) d.e[k++] = {i, j, m[i * c + j]};
	return d;
}
Dispersa transpuesta(const Dispersa &a){
	Dispersa t{a.cols, a.filas, new Elemento[a.nnz], a.nnz};
	for (int k = 0; k < a.nnz; k++) t.e[k] = {a.e[k].col, a.e[k].fila, a.e[k].valor};
	return t;
}
// suma de dos dispersas del mismo tamano
Dispersa sumar(const Dispersa &a, const Dispersa &b){
	Elemento *tmp = new Elemento[a.nnz + b.nnz];
	int i = 0, j = 0, k = 0;
	auto antes = [](const Elemento &x, const Elemento &y){ return x.fila < y.fila || (x.fila == y.fila && x.col < y.col); };
	while (i < a.nnz && j < b.nnz){
		if (antes(a.e[i], b.e[j])) tmp[k++] = a.e[i++];
		else if (antes(b.e[j], a.e[i])) tmp[k++] = b.e[j++];
		else {
			double s = a.e[i].valor + b.e[j].valor;
			if (s != 0) tmp[k++] = {a.e[i].fila, a.e[i].col, s};
			i++; j++;
		}
	}
	while (i < a.nnz) tmp[k++] = a.e[i++];
	while (j < b.nnz) tmp[k++] = b.e[j++];
	Dispersa r{a.filas, a.cols, new Elemento[k], k};
	for (int x = 0; x < k; x++) r.e[x] = tmp[x];
	delete[] tmp;
	return r;
}
void mostrar(const Dispersa &d){
	cout << d.filas << "x" << d.cols << ", " << d.nnz << " no nulos:";
	for (int k = 0; k < d.nnz; k++) cout << " (" << d.e[k].fila << "," << d.e[k].col << ")=" << d.e[k].valor;
	cout << endl;
}
void imprimirDensa(const Dispersa &d){
	double *m = new double[d.filas * d.cols]();
	for (int k = 0; k < d.nnz; k++) m[d.e[k].fila * d.cols + d.e[k].col] = d.e[k].valor;
	for (int i = 0; i < d.filas; i++){
		for (int j = 0; j < d.cols; j++) cout << m[i * d.cols + j] << " ";
		cout << endl;
	}
	delete[] m;
}
int main(){
	double a[] = {5, 0, 0, 0,   0, 0, 3, 0,   0, 2, 0, 0};
	double b[] = {-5, 0, 0, 1,  0, 0, 0, 0,   0, 0, 0, 7};
	Dispersa A = desdeDensa(a, 3, 4), B = desdeDensa(b, 3, 4);
	mostrar(A); mostrar(B);
	Dispersa S = sumar(A, B), T = transpuesta(A);
	cout << "A + B: "; mostrar(S);
	imprimirDensa(S);
	cout << "A^T: "; mostrar(T);
	cout << "Memoria densa: " << 12 * sizeof(double) << " bytes; dispersa de A: " << A.nnz * sizeof(Elemento) << " bytes" << endl;
	delete[] A.e; delete[] B.e; delete[] S.e; delete[] T.e;
	return 0;
}

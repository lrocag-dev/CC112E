#include <iostream>
#include <iomanip>
using namespace std;
// Matriz irregular: la fila i tiene i+1 elementos (Triangulo de Pascal)
int main(){
	int n;
	cout << "Filas del triangulo: ";
	cin >> n;
	int **t = new int *[n];
	for (int i = 0; i < n; i++){
		t[i] = new int[i + 1];
		t[i][0] = t[i][i] = 1;
		for (int j = 1; j < i; j++) t[i][j] = t[i - 1][j - 1] + t[i - 1][j];
	}
	for (int i = 0; i < n; i++){
		cout << string((n - i - 1) * 2, ' ');
		for (int j = 0; j <= i; j++) cout << setw(4) << t[i][j];
		cout << endl;
	}
	long total = 0;
	for (int i = 0; i < n; i++) total += i + 1;
	cout << "Elementos almacenados: " << total << " (una matriz cuadrada usaria " << n * n << ")" << endl;
	for (int i = 0; i < n; i++) delete[] t[i];
	delete[] t;
	return 0;
}

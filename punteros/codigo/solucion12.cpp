#include <iostream>
#include <cmath>
using namespace std;
using Operacion = double (*)(double, double);

double suma(double a, double b){ return a + b; }
double resta(double a, double b){ return a - b; }
double producto(double a, double b){ return a * b; }
double cociente(double a, double b){ return b != 0 ? a / b : NAN; }

bool ascendente(int a, int b){ return a < b; }
bool descendente(int a, int b){ return a > b; }
void ordenar(int *a, int n, bool (*antes)(int, int)){
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - 1 - i; j++)
			if (!antes(*(a + j), *(a + j + 1))){
				int aux = *(a + j); *(a + j) = *(a + j + 1); *(a + j + 1) = aux;
			}
}
void aplicar(int *a, int n, int (*f)(int)){
	for (int *p = a; p < a + n; p++)
		*p = f(*p);
}
int cuadrado(int x){ return x * x; }

int main(){
	Operacion ops[] = {suma, resta, producto, cociente};
	const char simbolos[] = {'+', '-', '*', '/'};
	double x, y;
	cout << "Ingrese x y: ";
	cin >> x >> y;
	for (int i = 0; i < 4; i++)
		cout << x << " " << simbolos[i] << " " << y << " = " << ops[i](x, y) << endl;

	int a[] = {5, 2, 9, 1, 7};
	ordenar(a, 5, descendente);
	for (int v : a) cout << v << " ";
	cout << endl;
	ordenar(a, 5, ascendente);
	for (int v : a) cout << v << " ";
	cout << endl;
	aplicar(a, 5, cuadrado);
	for (int v : a) cout << v << " ";
	cout << endl;
	return 0;
}

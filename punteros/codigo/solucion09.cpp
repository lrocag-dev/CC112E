#include <iostream>
using namespace std;
// no puede modificar el arreglo; devuelve puntero al elemento o nullptr
const int *buscar(const int *a, int n, int clave){
	for (const int *p = a; p < a + n; p++)
		if (*p == clave)
			return p;
	return nullptr;
}
int main(){
	int a[] = {5, 8, 13, 21, 34};
	int b = 99;

	const int *p1 = a;            // dato constante, puntero modificable
	p1++;
	// *p1 = 0;                   // ERROR

	int *const p2 = a;            // puntero constante, dato modificable
	*p2 = 50;
	// p2++;                      // ERROR

	const int *const p3 = &b;     // ambos constantes
	// *p3 = 1; p3 = a;           // ERROR

	cout << "*p1=" << *p1 << " *p2=" << *p2 << " *p3=" << *p3 << endl;

	int clave;
	cout << "Clave a buscar: ";
	cin >> clave;
	const int *r = buscar(a, 5, clave);
	if (r)
		cout << "Encontrado en la posicion " << r - a << endl;
	else
		cout << "No encontrado" << endl;
	return 0;
}

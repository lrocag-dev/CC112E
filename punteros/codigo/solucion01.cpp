#include <iostream>
using namespace std;
int main(){
	int x = 25;
	int *p = &x;
	cout << "Valor de x: " << x << endl;
	cout << "Direccion de x (&x): " << &x << endl;
	cout << "Valor de p (direccion guardada): " << p << endl;
	cout << "Valor apuntado (*p): " << *p << endl;
	cout << "Direccion de p (&p): " << &p << endl;
	*p = 40;
	cout << "Tras *p = 40, x vale: " << x << endl;

	double y = 3.5;
	double *q = &y;
	*q = *q * 2;
	cout << "Tras duplicar con *q, y vale: " << y << endl;

	cout << "sizeof(int*) = " << sizeof(p) << ", sizeof(double*) = " << sizeof(q) << endl;
	cout << "sizeof(int) = " << sizeof(int) << ", sizeof(double) = " << sizeof(double) << endl;
	return 0;
}

#include <iostream>
using namespace std;
int main(){
	int a[] = {10, 20, 30, 40};
	int *p = a;

	int r = *p++;                       // usa 10 y luego avanza
	cout << "*p++    -> " << r << "  (ahora *p = " << *p << ")" << endl;
	r = (*p)++;                         // usa 20, a[1] pasa a 21
	cout << "(*p)++  -> " << r << "  (a[1] ahora " << a[1] << ")" << endl;
	r = *++p;                           // avanza y usa 30
	cout << "*++p    -> " << r << endl;
	r = ++*p;                           // a[2] pasa a 31
	cout << "++*p    -> " << r << "  (a[2] ahora " << a[2] << ")" << endl;

	int m[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
	cout << "m[1][2] = " << m[1][2] << " = *(*(m+1)+2) = " << *(*(m + 1) + 2) << endl;

	int (*fila)[4] = m;                 // puntero a arreglo de 4 enteros
	for (int i = 0; i < 3; i++, fila++){
		int s = 0;
		for (int *q = *fila; q < *fila + 4; q++) s += *q;
		cout << "Suma fila " << i << ": " << s << endl;
	}

	int *ap[3] = {m[0], m[1], m[2]};    // arreglo de 3 punteros a int
	cout << "ap[2][3] = " << ap[2][3] << endl;
	cout << "sizeof(int*[3]) = " << sizeof(ap) << ", sizeof(int(*)[4]) = " << sizeof(fila) << endl;
	return 0;
}

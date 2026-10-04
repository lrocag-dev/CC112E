#include <iostream>
using namespace std;
void tamano(int a[], int n){
	// aqui 'a' es un puntero: sizeof(a) NO es el tamano del arreglo
	cout << "Dentro de la funcion: sizeof(a) = " << sizeof(a)
	     << " (puntero), n = " << n << endl;
}
int main(){
	int a[5] = {10, 20, 30, 40, 50};
	cout << "sizeof(a) = " << sizeof(a) << " -> " << sizeof(a) / sizeof(a[0]) << " elementos" << endl;
	tamano(a, 5);
	for (int i = 0; i < 5; i++){
		cout << "i=" << i << "  a[i]=" << a[i]
		     << "  *(a+i)=" << *(a + i)
		     << "  *(i+a)=" << *(i + a)
		     << "  i[a]=" << i[a]
		     << "  &a[i]=" << &a[i] << "  a+i=" << a + i << endl;
	}
	int *p = a;
	cout << "p[2] = " << p[2] << ", *(p+2) = " << *(p + 2) << endl;
	p++;                       // valido: p es una variable
	cout << "Tras p++, *p = " << *p << endl;
	// a++;                    // ERROR: el nombre del arreglo no es modificable
	return 0;
}

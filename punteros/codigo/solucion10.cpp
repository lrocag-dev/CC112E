#include <iostream>
#include <cstring>
using namespace std;
enum Tipo { ENTERO, REAL, CARACTER };
void imprimir(const void *dato, Tipo t){
	switch (t){
		case ENTERO:   cout << *static_cast<const int *>(dato); break;
		case REAL:     cout << *static_cast<const double *>(dato); break;
		case CARACTER: cout << *static_cast<const char *>(dato); break;
	}
	cout << endl;
}
void intercambiarGenerico(void *a, void *b, size_t bytes){
	char *pa = static_cast<char *>(a);
	char *pb = static_cast<char *>(b);
	for (size_t i = 0; i < bytes; i++){
		char aux = pa[i];
		pa[i] = pb[i];
		pb[i] = aux;
	}
}
int main(){
	int i = 7;
	double d = 2.75;
	char c = 'Z';
	imprimir(&i, ENTERO);
	imprimir(&d, REAL);
	imprimir(&c, CARACTER);

	int x = 1, y = 2;
	double u = 1.5, v = 9.5;
	intercambiarGenerico(&x, &y, sizeof(int));
	intercambiarGenerico(&u, &v, sizeof(double));
	cout << x << " " << y << " " << u << " " << v << endl;
	return 0;
}

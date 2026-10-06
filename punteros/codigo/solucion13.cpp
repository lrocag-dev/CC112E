#include <iostream>
using namespace std;
// Dos punteros recorren los arreglos ordenados sin indices.
int fusionar(const int *a, int na, const int *b, int nb, int *salida){
	const int *pa = a, *ea = a + na;
	const int *pb = b, *eb = b + nb;
	int *ps = salida;
	while (pa < ea && pb < eb)
		*ps++ = (*pa <= *pb) ? *pa++ : *pb++;
	while (pa < ea) *ps++ = *pa++;
	while (pb < eb) *ps++ = *pb++;
	return ps - salida;
}
int interseccion(const int *a, int na, const int *b, int nb, int *salida){
	const int *pa = a, *ea = a + na;
	const int *pb = b, *eb = b + nb;
	int *ps = salida;
	while (pa < ea && pb < eb){
		if (*pa < *pb) pa++;
		else if (*pb < *pa) pb++;
		else {
			if (ps == salida || *(ps - 1) != *pa)   // evita repetidos
				*ps++ = *pa;
			pa++; pb++;
		}
	}
	return ps - salida;
}
int main(){
	int a[] = {1, 3, 5, 7, 9, 9};
	int b[] = {2, 3, 4, 9, 10};
	int f[20], i[20];
	int nf = fusionar(a, 6, b, 5, f);
	int ni = interseccion(a, 6, b, 5, i);
	cout << "Fusion: ";
	for (int k = 0; k < nf; k++) cout << f[k] << " ";
	cout << endl << "Interseccion: ";
	for (int k = 0; k < ni; k++) cout << i[k] << " ";
	cout << endl;
	return 0;
}

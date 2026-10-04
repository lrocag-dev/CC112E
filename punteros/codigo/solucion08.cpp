#include <iostream>
using namespace std;
// modifica el puntero del llamador: necesita puntero a puntero
void apuntarAlMayor(int *a, int n, int **resultado){
	*resultado = a;
	for (int *p = a + 1; p < a + n; p++)
		if (*p > **resultado)
			*resultado = p;
}
void avanzar(int **p, int k){
	*p += k;
}
int main(){
	int a[] = {4, 17, 9, 31, 12};
	int n = 5;
	int *mayor = nullptr;
	apuntarAlMayor(a, n, &mayor);
	cout << "Mayor: " << *mayor << " (posicion " << mayor - a << ")" << endl;
	*mayor = 0;                       // modifica el arreglo original
	cout << "Arreglo tras anular el mayor: ";
	for (int x : a) cout << x << " ";
	cout << endl;

	int *p = a;
	int **pp = &p;
	cout << "a[0] = " << **pp << endl;
	avanzar(pp, 2);
	cout << "Tras avanzar 2, *p = " << *p << endl;
	return 0;
}

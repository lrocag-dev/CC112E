#include <iostream>
using namespace std;
void invertir(int *ini, int *fin){
	while (ini < fin){
		int aux = *ini;
		*ini = *fin;
		*fin = aux;
		ini++;
		fin--;
	}
}
void mostrar(const int *a, int n){
	for (const int *p = a; p < a + n; p++)
		cout << *p << " ";
	cout << endl;
}
int main(){
	int a[100], n;
	cout << "n: ";
	cin >> n;
	for (int *p = a; p < a + n; p++)
		cin >> *p;
	invertir(a, a + n - 1);
	cout << "Arreglo invertido: ";
	mostrar(a, n);
	return 0;
}

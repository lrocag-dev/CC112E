#include <iostream>
using namespace std;
void intercambiar(int *a, int *b){
	int aux = *a;
	*a = *b;
	*b = aux;
}
void rotar(int *a, int *b, int *c){
	// a <- b, b <- c, c <- a (valor original)
	int aux = *a;
	*a = *b;
	*b = *c;
	*c = aux;
}
int main(){
	int x, y, z;
	cout << "Ingrese tres enteros: ";
	cin >> x >> y >> z;
	intercambiar(&x, &y);
	cout << "Tras intercambiar x e y: " << x << " " << y << " " << z << endl;
	rotar(&x, &y, &z);
	cout << "Tras rotar: " << x << " " << y << " " << z << endl;
	return 0;
}

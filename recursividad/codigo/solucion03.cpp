#include <iostream>
using namespace std;
int cantidadDigitos(long n){
	if (n < 0) n = -n;
	if (n < 10) return 1;
	return 1 + cantidadDigitos(n / 10);
}
int sumaDigitos(long n){
	if (n < 0) n = -n;
	if (n < 10) return n;
	return n % 10 + sumaDigitos(n / 10);
}
// invierte con acumulador (recursion de cola)
long invertir(long n, long acum = 0){
	if (n == 0) return acum;
	return invertir(n / 10, acum * 10 + n % 10);
}
int sumaDigitosIter(long n){
	if (n < 0) n = -n;
	int s = 0;
	while (n > 0){ s += n % 10; n /= 10; }
	return s;
}
int main(){
	long n;
	cout << "Numero: ";
	cin >> n;
	cout << "Digitos: " << cantidadDigitos(n) << endl;
	cout << "Suma de digitos (rec/iter): " << sumaDigitos(n) << " / " << sumaDigitosIter(n) << endl;
	cout << "Invertido: " << invertir(n) << endl;
	cout << (n == invertir(n) ? "Es capicua" : "No es capicua") << endl;
	return 0;
}

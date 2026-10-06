#include <iostream>
using namespace std;
typedef unsigned long long ull;
long pasos1 = 0, pasos2 = 0;
ull potenciaLineal(ull x, int n){
	pasos1++;
	if (n == 0) return 1;
	return x * potenciaLineal(x, n - 1);
}
// exponenciacion rapida: x^n = (x^(n/2))^2 [* x si n es impar]
ull potenciaRapida(ull x, int n){
	pasos2++;
	if (n == 0) return 1;
	ull mitad = potenciaRapida(x, n / 2);
	return (n % 2 == 0) ? mitad * mitad : mitad * mitad * x;
}
ull potenciaIter(ull x, int n){
	ull r = 1;
	while (n > 0){
		if (n & 1) r *= x;
		x *= x;
		n >>= 1;
	}
	return r;
}
int main(){
	ull x;
	int n;
	cout << "Base y exponente (resultado < 2^64): ";
	cin >> x >> n;
	cout << "Lineal:   " << potenciaLineal(x, n) << "  (" << pasos1 << " llamadas)" << endl;
	cout << "Rapida:   " << potenciaRapida(x, n) << "  (" << pasos2 << " llamadas)" << endl;
	cout << "Iterativa:" << potenciaIter(x, n) << endl;
	return 0;
}

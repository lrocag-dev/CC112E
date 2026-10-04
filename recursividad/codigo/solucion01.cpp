#include <iostream>
using namespace std;
typedef unsigned long long ull;
ull factorialRec(int n){
	if (n <= 1) return 1;                  // caso base
	return n * factorialRec(n - 1);        // caso recursivo
}
ull factorialIter(int n){
	ull r = 1;
	for (int i = 2; i <= n; i++) r *= i;
	return r;
}
int main(){
	int n;
	cout << "n (0-20): ";
	cin >> n;
	if (n < 0 || n > 20){
		cout << "Fuera de rango: 21! excede unsigned long long" << endl;
		return 1;
	}
	cout << n << "! recursivo = " << factorialRec(n) << endl;
	cout << n << "! iterativo = " << factorialIter(n) << endl;
	cout << "Tabla:" << endl;
	for (int i = 0; i <= n; i++)
		cout << i << "! = " << factorialIter(i) << endl;
	return 0;
}

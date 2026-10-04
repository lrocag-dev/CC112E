#include <iostream>
using namespace std;
int total = 0;
// genera todas las cadenas de n pares de parentesis bien formadas
void generar(char *buf, int pos, int abiertos, int cerrados, int n){
	if (pos == 2 * n){
		buf[pos] = '\0';
		cout << buf << endl;
		total++;
		return;
	}
	if (abiertos < n){
		buf[pos] = '(';
		generar(buf, pos + 1, abiertos + 1, cerrados, n);
	}
	if (cerrados < abiertos){
		buf[pos] = ')';
		generar(buf, pos + 1, abiertos, cerrados + 1, n);
	}
}
long catalan(int n){            // C(n) = suma C(i)*C(n-1-i)
	if (n == 0) return 1;
	long s = 0;
	for (int i = 0; i < n; i++) s += catalan(i) * catalan(n - 1 - i);
	return s;
}
int main(){
	int n;
	cout << "Pares (1-8): ";
	cin >> n;
	char buf[40];
	generar(buf, 0, 0, 0, n);
	cout << "Total: " << total << "  (numero de Catalan C" << n << " = " << catalan(n) << ")" << endl;
	return 0;
}

#include <iostream>
using namespace std;
long movimientos = 0;
void hanoi(int n, char origen, char destino, char auxiliar){
	if (n == 0) return;
	hanoi(n - 1, origen, auxiliar, destino);
	movimientos++;
	cout << "Mover disco " << n << " de " << origen << " a " << destino << endl;
	hanoi(n - 1, auxiliar, destino, origen);
}
int main(){
	int n;
	cout << "Discos (1-10): ";
	cin >> n;
	hanoi(n, 'A', 'C', 'B');
	cout << "Total de movimientos: " << movimientos
	     << " (2^" << n << " - 1 = " << (1L << n) - 1 << ")" << endl;
	return 0;
}

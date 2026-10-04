#include <iostream>
#include <cstdlib>
using namespace std;
const int MAXN = 12;
int col[MAXN];          // col[f] = columna de la reina en la fila f
int n, soluciones = 0;
bool seguro(int f, int c){
	for (int i = 0; i < f; i++)
		if (col[i] == c || abs(col[i] - c) == f - i)   // misma columna o diagonal
			return false;
	return true;
}
void resolver(int f, bool imprimir){
	if (f == n){
		soluciones++;
		if (imprimir && soluciones == 1){
			for (int i = 0; i < n; i++){
				for (int j = 0; j < n; j++) cout << (col[i] == j ? "Q " : ". ");
				cout << endl;
			}
		}
		return;
	}
	for (int c = 0; c < n; c++)
		if (seguro(f, c)){
			col[f] = c;
			resolver(f + 1, imprimir);
		}
}
int main(){
	cout << "n (1-" << MAXN << "): ";
	cin >> n;
	resolver(0, true);
	cout << "Soluciones para n=" << n << ": " << soluciones << endl;
	return 0;
}

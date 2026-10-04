#include <iostream>
using namespace std;
// El ORDEN de las instrucciones respecto a la llamada recursiva cambia el resultado
void descendente(int n){
	if (n == 0) return;
	cout << n << " ";
	descendente(n - 1);
}
void ascendente(int n){
	if (n == 0) return;
	ascendente(n - 1);
	cout << n << " ";
}
void ambos(int n){
	if (n == 0) return;
	cout << n << " ";
	ambos(n - 1);
	cout << n << " ";
}
void fila(int k){ if (k == 0) return; cout << '*'; fila(k - 1); }
void triangulo(int n){
	if (n == 0) return;
	triangulo(n - 1);               // primero las filas menores
	fila(n);
	cout << endl;
}
void trianguloInvertido(int n){
	if (n == 0) return;
	fila(n);
	cout << endl;
	trianguloInvertido(n - 1);
}
int main(){
	int n;
	cout << "n: ";
	cin >> n;
	descendente(n); cout << endl;
	ascendente(n); cout << endl;
	ambos(n); cout << endl;
	triangulo(n);
	trianguloInvertido(n);
	return 0;
}

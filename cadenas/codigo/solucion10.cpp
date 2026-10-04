#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
// devuelve false si la cadena no es un entero valido
bool aEntero(const char *s, long &resultado){
	while (*s == ' ') s++;
	int signo = 1;
	if (*s == '+' || *s == '-'){ if (*s == '-') signo = -1; s++; }
	if (*s == '\0') return false;
	long v = 0;
	for (; *s; s++){
		if (*s < '0' || *s > '9') return false;
		v = v * 10 + (*s - '0');
	}
	resultado = signo * v;
	return true;
}
int main(){
	char s[50];
	cout << "Ingrese un numero: ";
	cin.getline(s, 50);
	long v;
	if (aEntero(s, v))
		cout << "Conversion propia: " << v << " (doble: " << 2 * v << ")" << endl;
	else
		cout << "Conversion propia: cadena invalida" << endl;

	char *fin;
	double d = strtod(s, &fin);
	cout << "strtod: " << d << ", sobrante: \"" << fin << "\"" << endl;
	cout << "atoi: " << atoi(s) << endl;
	cout << "to_string(" << 3.14 << ") = " << to_string(3.14) << endl;
	return 0;
}

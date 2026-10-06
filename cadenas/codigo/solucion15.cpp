#include <iostream>
#include <cstdlib>
#include <cctype>
using namespace std;
// Evalua expresiones con + - * / sin parentesis, respetando precedencia.
// Gramatica: expr = term { (+|-) term } ; term = numero { (*|/) numero }
const char *p;
void saltar(){ while (*p == ' ') p++; }
double numero(){
	saltar();
	char *fin;
	double v = strtod(p, &fin);
	if (fin == p){ cout << "Error: se esperaba un numero cerca de \"" << p << "\"" << endl; exit(1); }
	p = fin;
	return v;
}
double termino(){
	double v = numero();
	for (;;){
		saltar();
		if (*p == '*'){ p++; v *= numero(); }
		else if (*p == '/'){
			p++;
			double d = numero();
			if (d == 0){ cout << "Error: division por cero" << endl; exit(1); }
			v /= d;
		}
		else return v;
	}
}
double expresion(){
	double v = termino();
	for (;;){
		saltar();
		if (*p == '+'){ p++; v += termino(); }
		else if (*p == '-'){ p++; v -= termino(); }
		else return v;
	}
}
int main(){
	char s[200];
	cout << "Expresion: ";
	cin.getline(s, 200);
	p = s;
	double r = expresion();
	saltar();
	if (*p != '\0'){ cout << "Error: caracter inesperado '" << *p << "'" << endl; return 1; }
	cout << "Resultado: " << r << endl;
	return 0;
}

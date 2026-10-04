#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
// "aaabccdd" -> "a3b1c2d2"
void comprimir(const char *s, char *out){
	while (*s){
		char c = *s;
		int cuenta = 0;
		while (*s == c){ cuenta++; s++; }
		*out++ = c;
		out += sprintf(out, "%d", cuenta);
	}
	*out = '\0';
}
// "a3b1c2d2" -> "aaabccdd"
void descomprimir(const char *s, char *out){
	while (*s){
		char c = *s++;
		char *fin;
		long cuenta = strtol(s, &fin, 10);
		s = fin;
		for (long i = 0; i < cuenta; i++) *out++ = c;
	}
	*out = '\0';
}
int main(){
	char s[200], c[400], d[400];
	cout << "Cadena (sin digitos): ";
	cin.getline(s, 200);
	comprimir(s, c);
	cout << "Comprimida: " << c << endl;
	descomprimir(c, d);
	cout << "Descomprimida: " << d << endl;
	return 0;
}

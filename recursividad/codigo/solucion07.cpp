#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
bool palindromo(const char *s, int ini, int fin){
	while (ini < fin && !isalnum((unsigned char)s[ini])) ini++;     // saltar simbolos
	while (ini < fin && !isalnum((unsigned char)s[fin])) fin--;
	if (ini >= fin) return true;                                    // caso base
	if (tolower((unsigned char)s[ini]) != tolower((unsigned char)s[fin])) return false;
	return palindromo(s, ini + 1, fin - 1);
}
void invertirCadena(char *s, int ini, int fin){
	if (ini >= fin) return;
	char aux = s[ini]; s[ini] = s[fin]; s[fin] = aux;
	invertirCadena(s, ini + 1, fin - 1);
}
void imprimirAlReves(const char *s){          // sin modificar la cadena
	if (*s == '\0') return;
	imprimirAlReves(s + 1);
	cout << *s;
}
int main(){
	char s[200];
	cout << "Cadena: ";
	cin.getline(s, 200);
	cout << (palindromo(s, 0, strlen(s) - 1) ? "Es palindromo" : "No es palindromo") << endl;
	cout << "Al reves: ";
	imprimirAlReves(s);
	cout << endl;
	invertirCadena(s, 0, strlen(s) - 1);
	cout << "Invertida: " << s << endl;
	return 0;
}

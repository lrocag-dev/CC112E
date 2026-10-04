#include <iostream>
#include <cctype>
using namespace std;
void invertir(char *s){
	char *ini = s, *fin = s;
	while (*fin) fin++;
	fin--;
	while (ini < fin){
		char aux = *ini; *ini = *fin; *fin = aux;
		ini++; fin--;
	}
}
bool esPalindromo(const char *s){
	const char *i = s, *j = s;
	while (*j) j++;
	j--;
	while (i < j){
		while (i < j && !isalnum(static_cast<unsigned char>(*i))) i++;
		while (i < j && !isalnum(static_cast<unsigned char>(*j))) j--;
		if (tolower(static_cast<unsigned char>(*i)) != tolower(static_cast<unsigned char>(*j)))
			return false;
		i++; j--;
	}
	return true;
}
int main(){
	char s[200];
	cout << "Cadena: ";
	cin.getline(s, 200);
	cout << (esPalindromo(s) ? "Es palindromo" : "No es palindromo") << endl;
	invertir(s);
	cout << "Invertida: " << s << endl;
	return 0;
}

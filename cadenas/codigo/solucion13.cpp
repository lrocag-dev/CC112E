#include <iostream>
#include <cstring>
using namespace std;
// expande alrededor del centro [i, j] y devuelve la longitud del palindromo
int expandir(const char *s, int n, int i, int j){
	while (i >= 0 && j < n && s[i] == s[j]){ i--; j++; }
	return j - i - 1;
}
int main(){
	char s[200];
	cout << "Cadena: ";
	cin.getline(s, 200);
	int n = strlen(s);
	int mejorIni = 0, mejorLong = n > 0 ? 1 : 0;
	for (int c = 0; c < n; c++){
		int impar = expandir(s, n, c, c);
		int par = expandir(s, n, c, c + 1);
		int l = impar > par ? impar : par;
		if (l > mejorLong){
			mejorLong = l;
			mejorIni = c - (l - 1) / 2;
		}
	}
	char res[200];
	strncpy(res, s + mejorIni, mejorLong);
	res[mejorLong] = '\0';
	cout << "Subcadena palindroma mas larga: " << res << " (" << mejorLong << ")" << endl;
	return 0;
}

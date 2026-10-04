#include <iostream>
#include <cctype>
using namespace std;
void frecuencias(const char *s, int f[26]){
	for (int i = 0; i < 26; i++) f[i] = 0;
	for (; *s; s++)
		if (isalpha(static_cast<unsigned char>(*s)))
			f[tolower(static_cast<unsigned char>(*s)) - 'a']++;
}
bool anagramas(const char *a, const char *b){
	int fa[26], fb[26];
	frecuencias(a, fa);
	frecuencias(b, fb);
	for (int i = 0; i < 26; i++)
		if (fa[i] != fb[i]) return false;
	return true;
}
int main(){
	char a[100], b[100];
	cout << "Primera frase: ";
	cin.getline(a, 100);
	cout << "Segunda frase: ";
	cin.getline(b, 100);
	cout << (anagramas(a, b) ? "Son anagramas" : "No son anagramas") << endl;
	int f[26];
	frecuencias(a, f);
	cout << "Frecuencias de la primera: ";
	for (int i = 0; i < 26; i++)
		if (f[i]) cout << char('a' + i) << "=" << f[i] << " ";
	cout << endl;
	return 0;
}

#include <iostream>
#include <cstring>
using namespace std;
int contador = 0;
void permutar(char *s, int k, int n){
	if (k == n - 1){
		cout << s << " ";
		contador++;
		return;
	}
	for (int i = k; i < n; i++){
		swap(s[k], s[i]);          // elegir
		permutar(s, k + 1, n);     // explorar
		swap(s[k], s[i]);          // deshacer (backtracking)
	}
}
// sin repetidos: no usar el mismo caracter dos veces en la misma posicion
void permutarUnicas(char *s, int k, int n){
	if (k == n - 1){ cout << s << " "; contador++; return; }
	bool usado[256] = {false};
	for (int i = k; i < n; i++){
		unsigned char c = s[i];
		if (usado[c]) continue;
		usado[c] = true;
		swap(s[k], s[i]);
		permutarUnicas(s, k + 1, n);
		swap(s[k], s[i]);
	}
}
int main(){
	char s[20];
	cout << "Cadena (max 8): ";
	cin >> s;
	char t[20];
	strcpy(t, s);
	permutar(s, 0, strlen(s));
	cout << "\nTotal: " << contador << endl;
	contador = 0;
	permutarUnicas(t, 0, strlen(t));
	cout << "\nTotal sin repetidos: " << contador << endl;
	return 0;
}

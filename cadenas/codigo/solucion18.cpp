#include <iostream>
#include <ranges>
#include <string>
#include <string_view>
#include <algorithm>
#include <cctype>
using namespace std;
// Normaliza: solo letras, en minuscula (vista perezosa, sin construir cadenas intermedias)
auto normalizar(string_view s){
	return s
		| views::filter([](unsigned char c){ return isalpha(c); })
		| views::transform([](unsigned char c){ return static_cast<char>(tolower(c)); });
}
bool esPalindromo(string_view s){
	auto n = normalizar(s);
	return ranges::equal(n, n | views::reverse);
}
int main(){
	string s = "Anita lava la tina";
	cout << boolalpha << esPalindromo(s) << endl;
	cout << esPalindromo("Hola mundo") << endl;

	cout << "Normalizada: ";
	for (char c : normalizar("Hola, Mundo 2026!")) cout << c;
	cout << endl;

	// dividir en palabras con views::split y contarlas
	string_view frase = "el veloz zorro salta";
	int palabras = 0;
	for (auto parte : frase | views::split(' ')){
		string p(parte.begin(), parte.end());
		cout << p << "(" << p.size() << ") ";
		palabras++;
	}
	cout << "\nPalabras: " << palabras << endl;

	cout << "Mayusculas: ";
	for (char c : frase | views::transform([](unsigned char c){ return static_cast<char>(toupper(c)); }))
		cout << c;
	cout << endl;
	cout << "Primeras 7 letras: ";
	for (char c : frase | views::take(7)) cout << c;
	cout << endl;
	return 0;
}

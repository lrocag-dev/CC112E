#include <iostream>
#include <string>
using namespace std;
const char DIG[] = "0123456789ABCDEF";
string aBase(unsigned long n, int base){
	if (n < (unsigned long)base) return string(1, DIG[n]);
	return aBase(n / base, base) + DIG[n % base];
}
long deBase(const string &s, int base, size_t i = 0, long acum = 0){
	if (i == s.size()) return acum;
	char c = toupper(s[i]);
	int v = (c >= 'A') ? c - 'A' + 10 : c - '0';
	return deBase(s, base, i + 1, acum * base + v);
}
string aBinarioIter(unsigned long n){
	if (n == 0) return "0";
	string r;
	while (n > 0){ r.insert(r.begin(), char('0' + n % 2)); n /= 2; }
	return r;
}
int main(){
	unsigned long n;
	int base;
	cout << "Numero decimal y base (2-16): ";
	cin >> n >> base;
	string s = aBase(n, base);
	cout << n << " en base " << base << " = " << s << endl;
	cout << "De vuelta a decimal: " << deBase(s, base) << endl;
	cout << "Binario iterativo: " << aBinarioIter(n) << endl;
	return 0;
}

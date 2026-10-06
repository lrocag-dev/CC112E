#include <iostream>
#include <algorithm>
#include <compare>
#include <string>
#include <vector>
using namespace std;
class Version {
	int mayor, menor, parche;
public:
	Version(int a, int b, int c) : mayor(a), menor(b), parche(c) {}
	// una sola linea genera <, <=, >, >=, ==, != comparando miembro a miembro
	auto operator<=>(const Version &) const = default;
	string texto() const { return to_string(mayor) + "." + to_string(menor) + "." + to_string(parche); }
};
class Fraccion {
	long num, den;
	static long mcd(long a, long b){ return b == 0 ? (a < 0 ? -a : a) : mcd(b, a % b); }
public:
	Fraccion(long n, long d) : num(n), den(d){
		if (den < 0){ num = -num; den = -den; }
		long g = mcd(num, den);
		if (g > 1){ num /= g; den /= g; }
	}
	// comparacion con orden propio: a/b <=> c/d  ==  a*d <=> c*b
	strong_ordering operator<=>(const Fraccion &o) const { return num * o.den <=> o.num * den; }
	bool operator==(const Fraccion &o) const { return num == o.num && den == o.den; }
	string texto() const { return to_string(num) + "/" + to_string(den); }
};
int main(){
	Version a(1, 4, 2), b(1, 10, 0), c(1, 4, 2);
	cout << boolalpha << (a < b) << " " << (a == c) << " " << (b >= a) << " " << (a != b) << endl;

	vector<Version> vs = {{2, 0, 0}, {1, 10, 0}, {1, 4, 2}, {1, 4, 10}};
	ranges::sort(vs);
	for (const auto &v : vs) cout << v.texto() << " ";
	cout << endl;
	cout << "Maxima: " << ranges::max_element(vs)->texto() << endl;

	Fraccion x(1, 2), y(2, 4), z(3, 5);
	cout << x.texto() << " == " << y.texto() << ": " << (x == y) << endl;
	cout << x.texto() << " < " << z.texto() << ": " << (x < z) << endl;
	vector<Fraccion> fs = {{3, 4}, {1, 3}, {-1, 2}, {5, 6}};
	ranges::sort(fs);
	for (const auto &f : fs) cout << f.texto() << " ";
	cout << endl;
	auto r = x <=> z;
	cout << (r < 0 ? "menor" : r > 0 ? "mayor" : "equivalente") << endl;
	return 0;
}

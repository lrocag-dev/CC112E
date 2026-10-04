#include <iostream>
#include <bit>
#include <format>
#include <string>
#include <vector>
using namespace std;
// RECURSIVO: incluir / excluir cada elemento
void subconjuntosRec(const vector<char> &v, size_t i, string &actual, vector<string> &res){
	if (i == v.size()){ res.push_back("{" + actual + "}"); return; }
	subconjuntosRec(v, i + 1, actual, res);               // excluir
	actual.push_back(v[i]);
	subconjuntosRec(v, i + 1, actual, res);               // incluir
	actual.pop_back();
}
// ITERATIVO: cada subconjunto es un numero cuyos bits indican la pertenencia
vector<string> subconjuntosIter(const vector<char> &v){
	vector<string> res;
	for (unsigned mascara = 0; mascara < (1u << v.size()); mascara++){
		string s;
		for (size_t i = 0; i < v.size(); i++)
			if (mascara >> i & 1) s += v[i];
		res.push_back("{" + s + "}");
	}
	return res;
}
int main(){
	vector<char> v = {'a', 'b', 'c', 'd'};
	vector<string> r1;
	string actual;
	subconjuntosRec(v, 0, actual, r1);
	auto r2 = subconjuntosIter(v);
	cout << "Recursivo (" << r1.size() << "): ";
	for (auto &s : r1) cout << s << " ";
	cout << endl << "Iterativo (" << r2.size() << "): ";
	for (auto &s : r2) cout << s << " ";
	cout << endl;

	// utilidades de <bit> (C++20)
	cout << "Subconjuntos de tamano 2: ";
	for (unsigned m = 0; m < 16; m++)
		if (popcount(m) == 2) cout << format("{:04b} ", m);
	cout << endl;
	for (unsigned x : {1u, 6u, 16u, 100u})
		cout << format("{:>3}: potencia de 2? {:<5} bits necesarios: {}", x, has_single_bit(x), bit_width(x)) << endl;
	cout << "Redondeo a potencia de 2 de 100: " << bit_ceil(100u) << endl;
	return 0;
}

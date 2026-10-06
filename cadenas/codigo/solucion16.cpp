#include <iostream>
#include <string>
#include <string_view>
#include <vector>
using namespace std;
// string_view = (puntero, longitud): mira una cadena sin copiarla ni requerir '\0'
vector<string_view> dividir(string_view s, char sep){
	vector<string_view> partes;
	while (true){
		size_t pos = s.find(sep);
		partes.push_back(s.substr(0, pos));
		if (pos == string_view::npos) break;
		s.remove_prefix(pos + 1);
	}
	return partes;
}
string_view recortar(string_view s){
	while (!s.empty() && s.front() == ' ') s.remove_prefix(1);
	while (!s.empty() && s.back() == ' ') s.remove_suffix(1);
	return s;
}
int main(){
	const char texto[] = "  Ana ; Luis;Rosa  ;  Pedro ";
	string_view sv = texto;                  // sin copia
	cout << "Longitud: " << sv.size() << endl;
	auto partes = dividir(sv, ';');
	for (auto p : partes)
		cout << "[" << recortar(p) << "]" << endl;

	string_view linea = "https://www.uni.edu.pe/ciencias";
	cout << "Protocolo: " << linea.substr(0, linea.find("://")) << endl;
	cout << "Empieza con https: " << boolalpha << linea.starts_with("https") << endl;
	cout << "Termina en .pe: " << linea.ends_with(".pe") << endl;
	cout << "Termina en /ciencias: " << linea.ends_with("/ciencias") << endl;
	return 0;
}

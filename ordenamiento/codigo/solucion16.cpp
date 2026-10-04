#include <iostream>
#include <algorithm>
#include <ranges>
#include <string>
#include <vector>
using namespace std;
struct Alumno { string nombre; int grupo; double nota; };
void mostrar(const vector<int> &v){ for (int x : v) cout << x << " "; cout << endl; }
int main(){
	vector<int> v = {42, 7, 19, 3, 88, 25, 7, 61, 14};

	auto a = v;
	ranges::sort(a);
	cout << "sort:          "; mostrar(a);
	a = v;
	ranges::sort(a, ranges::greater{});
	cout << "descendente:   "; mostrar(a);

	a = v;
	ranges::partial_sort(a, a.begin() + 3);                // solo los 3 menores, en orden
	cout << "partial_sort 3: "; mostrar(a);

	a = v;
	ranges::nth_element(a, a.begin() + a.size() / 2);      // equivale a quickselect
	cout << "mediana (nth_element): " << a[a.size() / 2] << endl;

	vector<Alumno> alumnos = {{"Luis", 2, 14}, {"Ana", 1, 18}, {"Rosa", 2, 18}, {"Beto", 1, 11}, {"Eva", 2, 14}};
	// stable_sort conserva el orden relativo de los empates
	ranges::stable_sort(alumnos, ranges::greater{}, &Alumno::nota);
	cout << "stable_sort por nota desc:";
	for (const auto &x : alumnos) cout << " " << x.nombre << "(" << x.nota << ")";
	cout << endl;
	ranges::stable_sort(alumnos, {}, &Alumno::grupo);      // luego por grupo: la nota queda como desempate
	cout << "luego por grupo:";
	for (const auto &x : alumnos) cout << " " << x.nombre << "(g" << x.grupo << "," << x.nota << ")";
	cout << endl;
	cout << boolalpha << "esta ordenado por grupo? " << ranges::is_sorted(alumnos, {}, &Alumno::grupo)
	     << ", por nombre? " << ranges::is_sorted(alumnos, {}, &Alumno::nombre) << endl;
	return 0;
}

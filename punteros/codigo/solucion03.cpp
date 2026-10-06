#include <iostream>
using namespace std;
const int MAX = 100;
int main(){
	int a[MAX], n;
	cout << "n (max " << MAX << "): ";
	cin >> n;
	for (int *p = a; p < a + n; p++)
		cin >> *p;
	int suma = 0;
	for (const int *p = a; p != a + n; ++p)
		suma += *p;
	cout << "Suma: " << suma << endl;
	cout << "Promedio: " << static_cast<double>(suma) / n << endl;
	cout << "Elementos en orden inverso: ";
	for (const int *p = a + n - 1; p >= a; --p)
		cout << *p << " ";
	cout << endl;
	cout << "Elementos entre el primero y el ultimo: " << (a + n - 1) - a + 1 << endl;
	return 0;
}

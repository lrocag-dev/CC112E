#include <iostream>
#include <cstring>
using namespace std;
int main(){
	const int N = 5, L = 30;
	char nombres[N][L];
	cout << "Ingrese " << N << " nombres:" << endl;
	for (int i = 0; i < N; i++){
		cout << i + 1 << ": ";
		cin.getline(nombres[i], L);
	}
	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < N - 1 - i; j++)
			if (strcmp(nombres[j], nombres[j + 1]) > 0){
				char aux[L];
				strcpy(aux, nombres[j]);
				strcpy(nombres[j], nombres[j + 1]);
				strcpy(nombres[j + 1], aux);
			}
	cout << "Orden alfabetico:" << endl;
	for (int i = 0; i < N; i++)
		cout << nombres[i] << endl;
	return 0;
}

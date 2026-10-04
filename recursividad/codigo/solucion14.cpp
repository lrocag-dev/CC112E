#include <iostream>
#include <stack>
#include <utility>
using namespace std;
const int N = 6;
// 0 = libre, 1 = pared
int lab[N][N] = {
	{0, 1, 0, 0, 0, 0},
	{0, 1, 0, 1, 1, 0},
	{0, 0, 0, 1, 0, 0},
	{1, 1, 0, 1, 0, 1},
	{0, 0, 0, 0, 0, 0},
	{0, 1, 1, 1, 1, 0}};
char camino[N][N];
bool resolver(int f, int c){
	if (f < 0 || c < 0 || f >= N || c >= N || lab[f][c] == 1 || camino[f][c] != 0) return false;
	camino[f][c] = '*';
	if (f == N - 1 && c == N - 1) return true;
	if (resolver(f + 1, c) || resolver(f, c + 1) || resolver(f - 1, c) || resolver(f, c - 1))
		return true;
	camino[f][c] = '.';                    // retroceder
	return false;
}
// Misma busqueda sin recursion: pila explicita (DFS), solo dice si hay camino
bool existeIterativo(){
	bool visto[N][N] = {};
	stack<pair<int, int>> pila;
	pila.push({0, 0});
	int df[] = {1, 0, -1, 0}, dc[] = {0, 1, 0, -1};
	while (!pila.empty()){
		auto [f, c] = pila.top();
		pila.pop();
		if (f < 0 || c < 0 || f >= N || c >= N || lab[f][c] == 1 || visto[f][c]) continue;
		visto[f][c] = true;
		if (f == N - 1 && c == N - 1) return true;
		for (int k = 0; k < 4; k++) pila.push({f + df[k], c + dc[k]});
	}
	return false;
}
int main(){
	if (resolver(0, 0)){
		cout << "Camino encontrado ('*' camino, '.' explorado, '#' pared):" << endl;
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++)
				cout << (lab[i][j] ? '#' : (camino[i][j] ? camino[i][j] : ' ')) << ' ';
			cout << endl;
		}
	} else cout << "Sin camino" << endl;
	cout << "Version iterativa con pila: " << (existeIterativo() ? "hay camino" : "sin camino") << endl;
	return 0;
}

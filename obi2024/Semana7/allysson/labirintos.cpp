#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void dfs(int nodo, int &movimentos, unordered_map<int, bool> &visitados, unordered_map<int, vector<int>> &arestas) {
    visitados[nodo] = true;
    for (int vizinho: arestas[nodo]) {
        if (!visitados[vizinho]) {
            movimentos++;
            dfs(vizinho, movimentos, visitados, arestas);
            movimentos++; // Para retornar ao nodo atual
        }
    }
}

int contaMovimentos(int inicio, unordered_map<int, vector<int>> &arestas) {
    int movimentos = 0;
    unordered_map<int, bool> visitados; // Para verificar se um nodo foi visitado
    for (auto &aresta: arestas) {
        visitados[aresta.first] = false;
    }

    // Iniciar a DFS a partir do nodo de início
    dfs(inicio, movimentos, visitados, arestas);

    return movimentos;
}

int main() {
    int T, N, V, A;
    cin >> T;
    for (int j = 0; j < T; j++) {
        cin >> N;
        cin >> V >> A;

        unordered_map<int, vector<int>> arestas;

        for (int i = 0; i < A; i++) {
            int I, F;
            cin >> I >> F;
            arestas[I].push_back(F);
            arestas[F].push_back(I);
        }
        cout << contaMovimentos(N, arestas) << endl;
    }

    return 0;
}

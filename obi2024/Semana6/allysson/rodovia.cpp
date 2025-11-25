#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>

using namespace std;

// Função para realizar uma busca em largura (BFS) a partir da cidade `inicio`
void bfs(int inicio, const unordered_map<int, vector<int>>& vizinhos, vector<bool>& visitado) {
    queue<int> fila;
    fila.push(inicio);
    visitado[inicio] = true;

    while (!fila.empty()) {
        // Retorna a adição mais recente a fila
        int cidade = fila.front();
        fila.pop();

        // Passa por todos os vizinhos e os adiciona na fila
        // Cada vizinho vizidado representa um caminho a partir da cidade início
        for (int vizinho : vizinhos.at(cidade)) {
            if (!visitado[vizinho]) {
                visitado[vizinho] = true;
                fila.push(vizinho);
            }
        }
    }
}

// Função para verificar se o grafo é fortemente conexo
bool verificaConectividade(int N, const unordered_map<int, vector<int>>& adj) {
    vector<bool> visitado(N + 1, false);

    // Verifica se todas as cidades são acessíveis a partir da cidade 1
    bfs(1, adj, visitado);
    for (int i = 1; i <= N; ++i) {
        if (!visitado[i]) {
            return false;
        }
    }

    // Cria o grafo transposto
    unordered_map<int, vector<int>> vizinhosTransposto;
    for (const auto& par : adj) {
        for (int vizinho : par.second) {
            vizinhosTransposto[vizinho].push_back(par.first);
        }
    }

    // Seta o vetor inteiro para falso
    fill(visitado.begin(), visitado.end(), false);

    // Verifica se todas as cidades podem alcançar a cidade 1 no grafo transposto
    bfs(1, vizinhosTransposto, visitado);
    for (int i = 1; i <= N; ++i) {
        if (!visitado[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    int N;
    cin >> N;

    unordered_map<int, vector<int>> adj;

    for (int i = 0; i < N; ++i) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
    }

    if (verificaConectividade(N, adj)) {
        cout << 'S' << endl;
    } else {
        cout << 'N' << endl;
    }

    return 0;
}

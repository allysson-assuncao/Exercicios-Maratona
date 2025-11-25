#include <bits/stdc++.h>
using namespace std;

// --- Área Global (Heap/Data Segment) ---
// Definimos o tamanho máximo esperado pelo problema (ex: 10^5 vértices)
const int MAXN = 100005;

// Vetor de Adjacência: Array de Vectors
// adj[1] contém a lista de vizinhos do vértice 1
vector<int> adj[MAXN]; 

// Array para marcar visitados (inicia tudo com false por padrão global)
bool visitado[MAXN];

// --- Função Recursiva ---
// Note que ela não precisa receber o grafo nem o array 'visitado'
void dfs(int u) {
    visitado[u] = true; // Marca atual
    
    // Itera sobre os vizinhos de 'u'
    for (int v : adj[u]) {
        if (!visitado[v]) {
            dfs(v); // Chamada recursiva
        }
    }
}

int main() {
    // Boilerplate de velocidade
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; // n = vértices, m = arestas
    cin >> n >> m;

    // Leitura das arestas
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        
        // Grafo não-direcionado: vai e volta
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Contagem de Componentes Conexos
    int componentes = 0;
    for (int i = 1; i <= n; i++) {
        // Se o vértice i ainda não foi visitado, ele inicia um novo componente
        if (!visitado[i]) {
            componentes++;
            dfs(i); // Essa chamada vai marcar todos conectados a 'i'
        }
    }

    cout << "Numero de componentes conexos: " << componentes << "\n";

    return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

void conectaCliente(const vector<string>& aplicacoesCliente, const unordered_map<string, unordered_set<int>>& aplicacoes, unordered_set<string>& conexoes, int cliente) {
    for (const string& aplicacaoCliente : aplicacoesCliente) {
        if (aplicacoes.find(aplicacaoCliente) != aplicacoes.end()) {
            for (int servidor : aplicacoes.at(aplicacaoCliente)) {
                conexoes.insert(to_string(cliente) + "-" + to_string(servidor));
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    while (N != 0 || M != 0) {
        unordered_map<string, unordered_set<int>> aplicacoes;
        unordered_map<int, vector<string>> clientes;

        // Leitura dos servidores
        for (int i = 0; i < N; i++) {
            int S;
            cin >> S;
            for (int j = 0; j < S; j++) {
                string A;
                cin >> A;
                aplicacoes[A].insert(i);
            }
        }

        // Leitura dos clientes
        for (int i = 0; i < M; i++) {
            int C;
            cin >> C;
            for (int j = 0; j < C; j++) {
                string A;
                cin >> A;
                clientes[i].push_back(A);
            }
        }

        // O set impede o armazenamento de conexões duplicadas
        unordered_set<string> conexoes_unicas;

        // Processamento das conexões
        for (int i = 0; i < M; i++) {
            conectaCliente(clientes[i], aplicacoes, conexoes_unicas, i);
        }

        cout << conexoes_unicas.size() << endl;
        cin >> N >> M;
    }
    return 0;
}

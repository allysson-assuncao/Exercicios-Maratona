#include <iostream>
#include <vector>

using namespace std;

// Função recursiva para encontrar se há um caminho de A para B
bool encontraRodovia(int A, int B, const vector<pair<int, int>>& rodovias, vector<bool>& visitado) {
    if (A == B) {
        return true;
    }

    visitado[A] = true;

    for (const auto& rodovia : rodovias) {
        if (rodovia.first == A && !visitado[rodovia.second]) {
            if (encontraRodovia(rodovia.second, B, rodovias, visitado)) {
                return true;
            }
        }
    }

    return false;
}

// Função principal para verificar se todas as cidades são acessíveis de qualquer cidade
bool verificaConectividade(int N, const vector<pair<int, int>>& rodovias) {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (i != j) {
                vector<bool> visitado(N + 1, false);
                if (!encontraRodovia(i, j, rodovias, visitado)) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> rodovias(N);

    for (int i = 0; i < N; ++i) {
        cin >> rodovias[i].first >> rodovias[i].second;
    }

    if (verificaConectividade(N, rodovias)) {
        cout << 'S' << endl;
    } else {
        cout << 'N' << endl;
    }

    return 0;
}

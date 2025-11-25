#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int N, M, C;
    cin >> N >> M >> C;

    vector<pair<int, int>> preferencias(N);

    for (int i = 0; i < N; ++i) {
        int A, D;
        cin >> A >> D;
        preferencias[i] = {A, D};
    }

    int trocas = 0;
    unordered_set<int> compartilhadas;

    while (true) {
        compartilhadas.insert(C);
        bool trocaOcorreu = false;
        for (int i = 0; i < N; ++i) {
            if (preferencias[i].second == C) {
                C = preferencias[i].first;
                trocas++;
                trocaOcorreu = true;
                break;
            }
        }
        if (!trocaOcorreu) {
            cout << trocas << endl;
            return 0;
        }
        if (compartilhadas.count(C)) {
            cout << -1 << endl;
            return 0;
        }
    }

}

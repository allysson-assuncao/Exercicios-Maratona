#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
    int N, C;
    cin >> N >> C;

    unordered_set<int> todosPacientes;
    unordered_set<int> infectantes;

    for (int i = 0; i < C; ++i) {
        int P, I;
        cin >> P >> I;

        infectantes.insert(P);

        for (int j = 0; j < I; ++j) {
            int X;
            cin >> X;
            todosPacientes.insert(X);
        }
    }

    vector<int> pacientes0;
    for (int i = 1; i <= N; ++i) {
        //se o paciente infectou mas não foi infectado ele é um paciente 0
        if (infectantes.find(i) != infectantes.end() && todosPacientes.find(i) == todosPacientes.end()) {
            pacientes0.push_back(i);
        }
    }

    sort(pacientes0.begin(), pacientes0.end());

    for (auto &paciente : pacientes0) {
        cout << paciente << endl;
    }

    return 0;
}

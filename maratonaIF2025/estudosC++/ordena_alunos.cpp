#include <bits/stdc++.h>
using namespace std;

// 1. Definição da Struct/"Classe"
struct Aluno {
    string nome;
    int nota;
};

// 2. Função de Comparação personalizada
// Retorna true se 'a' deve vir antes de 'b' na fila
bool comparaAlunos(Aluno a, Aluno b) {
    if (a.nota != b.nota) {
        return a.nota > b.nota;
    }
    return a.nome < b.nome;
}

int main() {
    // Otimização de entrada e saída para cin e cout
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Aluno> turma(n);

    for (int i = 0; i < n; i++) {
        cin >> turma[i].nome >> turma[i].nota;
    }

    // 3. Chamada do Sort com a função de comparação personalizada
    sort(turma.begin(), turma.end(), comparaAlunos);

    for (Aluno x : turma) {
        cout << x.nome << " " << x.nota << "\n";
    }

    return 0;
}

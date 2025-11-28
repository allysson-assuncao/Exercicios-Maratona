#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int totalEventos, quantImplicacoes, quantVerdadeiros;
    cin >> totalEventos >> quantImplicacoes >> quantVerdadeiros;

    vector<pair<int, int>> implicacoes;
    set<int> verdadeiros;

    for (int i = 0; i < quantImplicacoes; i++)
    {
        cin >> implicacoes[i].first >> implicacoes[i].second;
    }

    for (int i = 0; i < quantVerdadeiros; i++)
    {
        int evento;
        cin >> evento;
        verdadeiros.insert(evento);
    }

    // 1 forma: Toda consequência de uma causa verdadeira é verdadeira
    // 2 forma: Se uma consequência verdadeira tem apenas uma causa, então ela é verdadeira

    for(auto x : verdadeiros) cout << x;

    return 0;
}

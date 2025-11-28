#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<char, int>> registros(n);
    set<int> amigosParticipantes;

    for (int i = 0; i < n; i++)
    {
        cin >> registros[i].first >> registros[i].second;
        if (registros[i].first != 'T')
        {
            amigosParticipantes.insert(registros[i].second);
        }
    }

    vector<pair<int, bool>> estadoAmigos(100, {0, true});

    for (int i = 0; i < n; i++)
    {
        const char operacao = registros[i].first;
        if (operacao == 'T') continue;
        const int valor = registros[i].second;

        if (operacao == 'R')
        {
            estadoAmigos[valor].second = false;
        }
        else if (operacao == 'E') estadoAmigos[valor].second = true;

        int tempoPassado = 1;

        if (i + 1 < n && registros[i+1].first == 'T') {
            tempoPassado = registros[i+1].second;
        }

        for (int id = 0; id < 100; id++) {
            if (!estadoAmigos[id].second) {
                estadoAmigos[id].first += tempoPassado;
            }
        }
    }

    for (int id : amigosParticipantes) {
        cout << id << " ";
        if (!estadoAmigos[id].second) {
            cout << "-1\n";
        } else {
            cout << estadoAmigos[id].first << "\n";
        }
    }

    return 0;
}

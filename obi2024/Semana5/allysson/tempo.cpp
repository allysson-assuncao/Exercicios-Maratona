#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int N;
    cin >> N;
    map<int, pair<int, bool>> amigos;
    char CAnterior;
    for (int i = 0; i < N; ++i) {
        char C;
        int I;
        cin >> C >> I;
        if (C != 'T') {
            //caso o amigo não esteja na lista ele é adicionado
            if (amigos.find(I) == amigos.end()) {
                amigos[I] = {0, false};
            }
            if (C == 'R' && i != 0) {
                amigos[I].second = false;
                //adicionando 1 ao tempo de resposta de todos os amigos não respondidos
                if (CAnterior != 'T') {
                    for (auto &amigo: amigos) {
                        if (!amigo.second.second && amigo.first != I) {
                            amigo.second.first++;
                        }
                    }
                }
            } else if (i != 0) {
                if (CAnterior != 'T') {
                    for (auto &amigo: amigos) {
                        if (!amigo.second.second) {
                            amigo.second.first++;
                        }
                    }
                }
                amigos[I].second = true;
            }
        } else {
            if (CAnterior != 'T') {
                for (auto &amigo: amigos) {
                    if (!amigo.second.second) {
                        amigo.second.first += I;
                    }
                }
            }
        }
        CAnterior = C;
    }
    for (const auto &amigo: amigos) {
        // Se o amigo não tiver respondido a todas as mensagens, imprime -1 como tempo de resposta total
        int tempo_resposta_total = amigo.second.second ? amigo.second.first : -1;
        cout << amigo.first << " " << tempo_resposta_total << endl;
    }

    return 0;
}

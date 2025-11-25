#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <limits>

using namespace std;

struct Cidade {
    int numero;
    int distancia;
    int origem;
    bool explorada;
};

int menorDistancia(vector<vector<pair<int, int>>>& grafo, int inicio, int fim) {
    int n = grafo.size();
    vector<Cidade> cidades(n + 1);
    for (int i = 1; i <= n; ++i) {
        //inicializando cada cidade
        //maior valor inteiro em c++ -> numeric_limits<int>::max()
        cidades[i] = {i, 10000, -1, false};
    }

    cidades[inicio].distancia = 0;
    cidades[inicio].origem = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> filaPrioridade;
    //buscando a partir da cidade de início
    filaPrioridade.push({0, inicio});

    while (!filaPrioridade.empty()) {
        //acessando a cidade com menor distância
        int cidadeAtual = filaPrioridade.top().second;
        filaPrioridade.pop();

        if (cidades[cidadeAtual].explorada)
            //pula o restante da iteração atual do loop e passa para a próxima cidade
            continue;

        cidades[cidadeAtual].explorada = true;

        //iterador que se passa por cada par de vizinhos da cidade atual
        for (auto& vizinha : grafo[cidadeAtual]) {
            int cidadeVizinha = vizinha.first;
            int distancia = vizinha.second;

            /*caso a distãncia da cidade vizinha até a atual seja maior que a distância do início até a cidade atual
            mais a distância da cidade vizinha até a atual*/
            if (cidades[cidadeVizinha].distancia > cidades[cidadeAtual].distancia + distancia) {
                cidades[cidadeVizinha].distancia = cidades[cidadeAtual].distancia + distancia;
                cidades[cidadeVizinha].origem = cidadeAtual;
                //adiciona a cidade que acabamos de explorar para a lista, para que seus vizinhos sejam analizados
                filaPrioridade.push({cidades[cidadeVizinha].distancia, cidadeVizinha});
            }
        }
    }

    return cidades[fim].distancia;
}

int main() {
    int N, A, B;
    cin >> N >> A >> B;

    //vetor de vetor de vizinhos
    vector<vector<pair<int, int>>> grafo(N + 1);

    for (int i = 1; i < N; ++i) {
        int P, Q, D;
        cin >> P >> Q >> D;
        //adicionando ambas as cidades como vizinhas uma da outra
        grafo[P].push_back({Q, D});
        grafo[Q].push_back({P, D});
    }

    int distancia = menorDistancia(grafo, A, B);
    cout << distancia << endl;

    return 0;
}

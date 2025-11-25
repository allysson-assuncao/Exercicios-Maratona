#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

// Função para realizar uma busca em largura (BFS) a partir dos eventos verdadeiros determinados pela agência
void verificaConsequencias(int inicio, const unordered_map<int, vector<int>> &causas, vector<bool> &visitado, vector<int> &verdadeiros) {
    queue<int> fila;
    fila.push(inicio);
    visitado[inicio] = true;
    verdadeiros.push_back(inicio);

    while (!fila.empty()) {
        int evento = fila.front();
        fila.pop();
        if (causas.find(evento) != causas.end()) {
            for (int consequencia: causas.at(evento)) {
                if (!visitado[consequencia]) {
                    visitado[consequencia] = true;
                    verdadeiros.push_back(consequencia);
                    fila.push(consequencia);
                }
            }
        }
    }
}

void verificaCausas(int inicio, const unordered_map<int, vector<int>> &consequencias, vector<int> &verdadeiros) {
    queue<int> fila;
    unordered_set<int> elementosNaFila;
    unordered_set<int> possiveisNovosVerdadeiros;

    fila.push(inicio);
    elementosNaFila.insert(inicio);
    bool mudanca = true;

    while (mudanca) {
        mudanca = false;
        while (!fila.empty()) {
            int evento = fila.front();
            /*cout << "Evento: " << evento << endl;*/
            elementosNaFila.erase(fila.front());
            fila.pop();

            auto it = consequencias.find(evento);
            if (it != consequencias.end()) {
                const vector<int>& causasEvento = it->second;
                if(elementosNaFila.empty() && causasEvento.size() == 1){
                    /*cout << "Passou direto: " << endl;*/
                    int causa = causasEvento[0];
                    verdadeiros.push_back(causa);
                    fila.push(causa);
                    elementosNaFila.insert(causa);
                    mudanca = true;
                }else{
                    for (int causa: consequencias.at(evento)) {
                        /*cout << "Causa: " << causa << endl;*/
                        if (elementosNaFila.find(causa) == elementosNaFila.end()) {
                            fila.push(causa);
                            elementosNaFila.insert(causa);
                            possiveisNovosVerdadeiros.insert(causa);
                        }/*else if(elementosNaFila.size() == 1){
                            return;
                        }*/
                    }
                    /*for(int elementoFila : elementosNaFila){
                        cout << "ElementoFila: " << elementoFila << endl;
                    }*/
                    if(elementosNaFila.size() == 1){
                        // Causa primaria encontrada
                        /*cout << "Deu certo: " << endl;*/
                        for(int verdadeiro : possiveisNovosVerdadeiros){
                            verdadeiros.push_back(verdadeiro);
                            mudanca = true;
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int E, I, V;
    cin >> E >> I >> V;

    unordered_map<int, vector<int>> causas;
    unordered_map<int, vector<int>> consequencias;

    for (int i = 0; i < I; ++i) {
        int A, B;
        cin >> A >> B;
        causas[A].push_back(B);
        consequencias[B].push_back(A);
    }

    vector<int> verdadeiros;
    vector<bool> visitado(E + 1, false);

    for (int i = 0; i < V; ++i) {
        int X;
        cin >> X;
        if (!visitado[X]) {
            verificaConsequencias(X, causas, visitado, verdadeiros);
        }
    }
    for (int evento: verdadeiros) {
        verificaCausas(evento, consequencias, verdadeiros);
    }

    sort(verdadeiros.begin(), verdadeiros.end());

    for (int evento: verdadeiros) {
        cout << evento << " ";
    }
    cout << endl;


    return 0;
}

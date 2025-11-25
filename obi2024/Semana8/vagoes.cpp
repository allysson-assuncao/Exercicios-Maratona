#include <iostream>
#include <vector>

using namespace std;

/*int main() {
    int N, L, V;
    cin >> N;
    vector<int> trem;

    for(int i = 0; i < N; i++){
        cin >> L;
        for(int j = 0; j < L; j ++){
            cin >> V;
            trem.push_back(V);
        }
        bool mudanca = true;
        int trocas = 0;

        while(mudanca){
            mudanca = false;
            for(int j = 0; j < L - 1; j++){
                if(trem[j] > trem[j + 1]){
                    int primeiro = trem[j];
                    trem[j] = trem[j + 1];
                    trem[j + 1] = primeiro;
                    trocas++;
                    mudanca = true;
                }
            }
        }
        cout << "Optimal train swapping takes " << trocas << " swaps." << endl;
        trem.clear();
    }

    return 0;
}*/

// Função para calcular o número de trocas necessárias para ordenar o trem
int calculaTrocas(vector<int>& trem, int L) {
    int trocas = 0;
    bool mudanca;

    //L - i - 1 --> Garantindo que após cada varrida completa do vetor, o limite é reduzido
    //Isso ocorre pois o maior valor não ordenado sempre é ordenado em cada passagem completa
    for(int i = 0; i < L - 1; i++) {
        mudanca = false;
        for(int j = 0; j < L - i - 1; j++) {
            if(trem[j] > trem[j + 1]) {
                // Inverte os vagões
                swap(trem[j], trem[j + 1]);
                trocas++;
                mudanca = true;
            }
        }
        if(!mudanca) break; // Se não houve troca, o trem já está ordenado
    }

    return trocas;
}

int main() {
    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        int L;
        cin >> L;

        vector<int> trem(L);
        for(int j = 0; j < L; j++) {
            cin >> trem[j];
        }

        cout << "Optimal train swapping takes " << calculaTrocas(trem, L) << " swaps." << endl;
    }

    return 0;
}

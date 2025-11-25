#include <iostream>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int posicoes[N];
    for (int i = 0; i < N; i++) {
        cin >> posicoes[i];
    }
    int deslizes[M];
    for (int i = 0; i < M; i++) {
        cin >> deslizes[i];
        deslizes[i] = deslizes[i] - 1;
    }
    int quantVezes[10];
    for (int &quantVez: quantVezes) {
        quantVez = 0;
    }
    int j;
    int anterior;
    for(int i = 0; i < M; i++){
        if(i == 0){
            anterior = 0;
            i++;
        }
        for (j = anterior; j != deslizes[i]; (deslizes[i] < anterior) ? j-- : j++) {
            quantVezes[posicoes[j]]++;
        }
        anterior = deslizes[i];
    }
    quantVezes[posicoes[j]]++;
    for (int i = 0; i < 10; ++i) {
        cout << quantVezes[i] << " ";
    }
    return 0;
}

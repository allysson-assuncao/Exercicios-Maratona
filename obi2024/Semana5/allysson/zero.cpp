#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> numeros;
    int entrada;
    int soma = 0;
    int contador = 0;
    for (int i = 0; i < N; ++i) {
        if(contador == N){
            break;
        }
        cin >> entrada;
        if (entrada == 0) {
            i -= 2;
            soma -= numeros[i + 1];
            numeros.pop_back();
        } else {
            numeros.push_back(entrada);
            soma += entrada;
        }
        contador++;
    }
    cout << soma << endl;
    return 0;
}

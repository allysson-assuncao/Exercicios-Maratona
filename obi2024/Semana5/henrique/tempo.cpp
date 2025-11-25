#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <limits>

using namespace std;


int main() {
    int N, zerosInARow = 0, soma = 0;

    cin >> N;

    vector<int> numeros;


    for(int i = 0; i < N; i++){
        int numero;
        cin >> numero;

        if(numero == 0 && numeros.size() >= 1){
            zerosInARow++;
            int o = i-zerosInARow;
            numeros.erase(numeros.begin() + o);
        }else {
            zerosInARow = 0;
            numeros.push_back(numero);
        }

    }

    for(int i = 0; i < numeros.size(); i++){
        //cout << numeros[i] << " ";
        soma += numeros[i];
    }
    cout << "\n" << soma;


    return 0;
}
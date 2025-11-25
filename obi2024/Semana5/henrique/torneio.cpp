#include <iostream>//
// Created by anybody on 11/04/24.
//

#include <vector>
#include <unordered_map>
#include <queue>
#include <limits>

using namespace std;


int main() {
    int grupo = -1;
    int vitorias = 0;


    for(int i = 0; i < 6; i++){
        char resultado;
        cin >> resultado;

        if(resultado == 'V'){
            vitorias++;
        }
    }

    if(vitorias != 0){
        if(vitorias <= 2){
            grupo = 1;
        }else if(vitorias <= 4){
            grupo = 2;
        }else{
            grupo = 3;
        }
    }

    cout << grupo;


    return 0;
}
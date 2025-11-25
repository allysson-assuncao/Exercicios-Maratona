#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <limits>

using namespace std;


int main() {
    int N, M;
    cin >> N >> M;

    char matriz[N][M];

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> matriz[i][j];
        }
    }



    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){

            if(matriz[i][j] == '.'){
                if(matriz[i-1][j] == 'o' ||
                   (matriz[i][j-1] == 'o' && matriz[i+1][j-1] == '#') ||
                   (matriz[i][j+1] == 'o' && matriz[i+1][j+1] == '#')){
                    matriz[i][j] = 'o';
                    j = -1;
                }
            }

        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << matriz[i][j] << " ";
        }
        cout << "\n";
    }


    return 0;
}

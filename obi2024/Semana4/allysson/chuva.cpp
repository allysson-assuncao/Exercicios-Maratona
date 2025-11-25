#include <iostream>
#include <string>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    string matrizCompleta;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c;
            cin >> c;
            matrizCompleta += c;
        }
        matrizCompleta += '\n';
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (matrizCompleta[i * (M + 1) + j] != '.')
                continue;
            if (i != 0 && matrizCompleta[(i - 1) * (M + 1) + j] == 'o') {
                matrizCompleta[i * (M + 1) + j] = 'o';
                j = -1;
            } else if (i != N - 1 && j != 0 && matrizCompleta[i * (M + 1) + (j - 1)] == 'o' && matrizCompleta[(i + 1) * (M + 1) + (j - 1)] == '#') {
                matrizCompleta[i * (M + 1) + j] = 'o';
                j = -1;
            } else if (i != N - 1 && j != M - 1 && matrizCompleta[i * (M + 1) + (j + 1)] == 'o' && matrizCompleta[(i + 1) * (M + 1) + (j + 1)] == '#') {
                matrizCompleta[i * (M + 1) + j] = 'o';
                j = -1;
            }
        }
    }
    cout << matrizCompleta;
    return 0;
}

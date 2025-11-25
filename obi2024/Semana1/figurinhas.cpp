#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, C, M;
    cin >> N >> C >> M;
    int carimbadas[C];
    for (int i = 0; i < C; i++) {
        cin >> carimbadas[i];
    }
    int compradas[M];
    for (int i = 0; i < M; i++) {
        cin >> compradas[i];
    }
    int faltam = C;
    for (int i = 0; i < C; ++i) {
        if (find(compradas, compradas + M, carimbadas[i]) != compradas + M) {
            carimbadas[0] = -1;
            faltam--;
        }
    }
    cout << faltam << endl;
    return 0;
}

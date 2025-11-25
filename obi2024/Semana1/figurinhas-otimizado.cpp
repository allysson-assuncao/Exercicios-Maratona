#include <iostream>
#include <algorithm>

using namespace std;

int binarySearch(int arr[], int target, int tamanho) {
    int left = 0;
    int right = tamanho - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

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
    for (int i = 0; i < C; ++i) {
        sort(compradas, compradas + M);
        int indice = binarySearch(compradas, carimbadas[i], M);
        if(indice != -1){
            carimbadas[i] = 0;
        }
    }
    int faltam = C;
    for (int i = 0; i < C; i++) {
        if (carimbadas[i] == 0) {
            faltam--;
        }
    }
    cout << faltam << endl;
    return 0;
}

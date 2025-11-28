#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Deslocamento (Multiplicação/Divisão por 2)
    int x = 1 << 5;           // 2^5 = 32
    int y = 32 >> 4;          // 32/2 = 16
    cout << x << " " << y << endl;

    return 0;
}
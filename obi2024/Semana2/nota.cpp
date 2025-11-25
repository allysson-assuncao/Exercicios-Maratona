#include <iostream>

using namespace std;

int main() {
    int B, T;
    cin >> B;
    cin >> T;
    if (B + T == 160) {
        cout << 0;
        return 0;
    }
    double areaT = (B + T) * 35;
    if (areaT > 5600) {
        cout << 1;
        return 0;
    } else {
        cout << 2;
        return 0;
    }
}

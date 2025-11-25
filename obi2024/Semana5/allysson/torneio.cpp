#include <iostream>

using namespace std;

int main() {
    char resultado;
    int grupo = 0;
    for (int i = 0; i < 6; ++i) {
        cin >> resultado;
        if (resultado == 'V') {
            grupo++;
        }
    }
    if (grupo == 0) {
        grupo = -1;
    } else if (grupo <= 2) {
        grupo = 1;
    } else if (grupo <= 4) {
        grupo = 2;
    }else{
        grupo = 3;
    }
    cout << grupo << endl;
    return 0;
}

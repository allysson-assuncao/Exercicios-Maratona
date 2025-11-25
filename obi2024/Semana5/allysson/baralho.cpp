#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main() {
    string cartas;
    getline(cin, cartas);

    //elementos únicos
    unordered_set<string> cartas_vistas;
    unordered_map<char, int> cartas_por_naipe;

    string resultado = "";

    for (int i = 0; i < cartas.size(); i += 3) {
        string carta = cartas.substr(i, 3);
        char naipe = carta[2];

        if (cartas_vistas.count(carta)) {
            cartas_por_naipe[naipe] = -1;
        } else if (cartas_por_naipe[naipe] != -1) {
            cartas_vistas.insert(carta);
            cartas_por_naipe[naipe]++;
        }
    }

    for (char naipe : {'C', 'E', 'U', 'P'}) {
        if (cartas_por_naipe[naipe] == -1) {
            resultado += "erro\n";
        } else {
            resultado += to_string(13 - cartas_por_naipe[naipe]) + "\n";
        }
    }

    cout << resultado << endl;

    return 0;
}

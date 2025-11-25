#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {10, 20, 30, 40, 50};

    // Busca o primeiro número >= 30
    auto it = lower_bound(v.begin(), v.end(), 30);

    if (it != v.end())
    {
        // Se v.end(), significa que não achou
        int valor = *it; // O asterisco pega o valor (como desreferenciar ponteiro)
        int indice = it - v.begin(); // Aritmética de ponteiros para pegar o índice (0, 1, 2...)

        cout << "Achei " << valor << " no indice " << indice << "\n"; // Achei 30 no indice 2
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<string, int> m;
    m["ana"] = 10;
    m["joao"] = 5;
    cout << m["ana"] << "\n"; // 10
    if (m.count("x")) cout << 1 << "\n"; // Verifica chave
    // Iterar
    for(auto p : m) cout << p.first << ":" << p.second;

    return 0;
}
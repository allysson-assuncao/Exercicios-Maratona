#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int N, X, P, M, G;
    cin >> N >> X;

    string titas;
    cin >> titas;

    cin >> P >> M >> G;

    map<char, int> tamanhos;

    tamanhos['P'] = P;
    tamanhos['M'] = M;
    tamanhos['G'] = G;

    vector<int> muralhas;
    muralhas.push_back(X);

    for (char tita : titas) {
        for(int i = 0; i < muralhas.size(); i++){
            if (tamanhos[tita] <= muralhas[i]) {
                /*cout << "Morreu: " << tita << endl;*/
                muralhas[i] -= tamanhos[tita];
                /*for(int muralha : muralhas){
                    cout << "Muralha: " << muralha << endl;
                }*/
                break;
            } else {
                /*cout << "Pulou: " << tita << endl;*/
                if((i + 1) == muralhas.size()){
                    /*cout << "Nova muralha" << endl;*/
                    muralhas.push_back(X);
                }
                /*for(int muralha : muralhas){
                    cout << "Muralha: " << muralha << endl;
                }*/
            }
        }
    }

    cout << muralhas.size() << endl;

    return 0;
}

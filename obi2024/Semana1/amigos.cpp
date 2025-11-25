#include <iostream>
#include <vector>

using namespace std;

int main() {
    int quantPredios;
    cin >> quantPredios;
    if(quantPredios < 2){
        return 0;
    }
    vector<int> vetAndares(quantPredios);
    int maiorDist = 0;
    for(int i = 0; i < quantPredios; ++i) {
        cin >> vetAndares[i];
    }
    for(int i = 0; i < quantPredios; ++i) {
        for(int j = i; j < quantPredios; ++j) {
            int dist = vetAndares[i] + j - i + vetAndares[j];
            if(dist > maiorDist){
                maiorDist = dist;
            }
        }
    }
    cout << maiorDist << endl;
    return 0;
}

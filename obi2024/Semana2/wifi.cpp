#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Sala {
private:
    int x1, y1, x2, y2, per;

public:
    Sala(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {
        this->per = abs((this->x2 - this->x1) + (this->y1 - this->y2));
    }
    bool operator<(const Sala& other) const {
        return per < other.per;
    }
    bool isDentro(const Sala& other) const {
        return (x1 > other.x1 && y1 < other.y1 && x2 < other.x2 && y2 > other.y2);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int qSalas;
    cin >> qSalas;
    vector<Sala> salas;
    for (int i = 0; i < qSalas; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        salas.push_back(Sala(x1, y1, x2, y2));
    }
    sort(salas.begin(), salas.end());
    for (size_t i = 0; i < salas.size(); i++) {
        for (size_t j = i + 1; j < salas.size(); j++) {
            if (salas[i].isDentro(salas[j])) {
                salas.erase(salas.begin() + j);
                j--;
            }
        }
    }
    cout << salas.size() << endl;
    return 0;
}

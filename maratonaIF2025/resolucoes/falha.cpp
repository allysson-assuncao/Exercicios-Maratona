#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> senhas;
    for (int i = 0; i < n; i++)
    {
        string senha;
        cin >> senha;
        senhas.push_back(senha);
    }

    int quantParesAcessos = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j) continue;
            if (senhas[i].find(senhas[j]) != string::npos)
            {
                quantParesAcessos++;
            }
        }
    }

    cout << quantParesAcessos << endl;

    return 0;
}

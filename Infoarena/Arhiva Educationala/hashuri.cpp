#include <fstream>
#include <vector>
using namespace std;

ifstream fin("hashuri.in");
ofstream fout("hashuri.out");

const int MOD = 666013;

vector<int> v[MOD];

inline vector<int>::iterator cauta(int val)
{
    int x = val % MOD;
    vector<int>::iterator it;
    for (it = v[x].begin(); it != v[x].end(); ++it)
        if (*it == val)
            return it;
    return v[x].end();
}

inline void adauga(int val)
{
    int x = val % MOD;
    if (cauta(val) == v[x].end())
        v[x].push_back(val);
}

inline void sterge(int val)
{
    int x = val % MOD;
    vector<int>::iterator it = cauta(val);
    if (it != v[x].end())
        v[x].erase(it);
}

int n, op, x;

int main()
{
    fin >> n;
    while (n--)
    {
        fin >> op >> x;
        if (op == 1)
            adauga(x);
        else if (op == 2)
            sterge(x);
        else
            fout << (cauta(x) != v[x % MOD].end()) << "\n";
    }
}

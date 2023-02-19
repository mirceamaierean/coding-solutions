#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

ifstream fin("color2.in");
ofstream fout("color2.out");

const int MAXN = 16005;

vector<int> T[MAXN], sol;
int frate[MAXN], tata[MAXN], fiu[MAXN];
bool sus[MAXN], jos[MAXN];

void dfs_jos(int u, int prv)
{
    int son[2], p = 0;
    jos[u] = true;
    for (int v : T[u])
        if (v != prv)
        {
            dfs_jos(v, u);
            son[p++] = v;
        }

    if (!p)
        return; // n-are fii
    jos[u] = (jos[son[0]] ^ 1) & (jos[son[1]] ^ 1);
}

void dfs_sus(int u, int prv)
{
    sus[u] = ((sus[tata[u]] ^ 1) | (jos[frate[u]]));
    for (int v : T[u])
        if (v != prv)
            dfs_sus(v, u);
}

int main()
{
    int n, u, v;

    fin >> n;
    for (int i = 1; i < n; ++i)
    {
        fin >> u >> v;
        T[u].push_back(v);
        T[v].push_back(u);
        tata[v] = u;
        if (fiu[u] != 0)
        {
            frate[fiu[u]] = v;
            frate[v] = fiu[u];
        }
        else
            fiu[u] = v;
    }

    dfs_jos(1, 0);
    dfs_sus(1, 0);

    for (int i = 1; i <= n; ++i)
        if (sus[i] & jos[i])
            sol.push_back(i);

    fout << sol.size() << "\n";
    for (size_t i = 0; i < sol.size(); ++i)
        fout << sol[i] << " ";

    return 0;
}

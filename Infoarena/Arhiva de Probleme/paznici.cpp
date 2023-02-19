#include <fstream>
#include <vector>
#include <bitset>
using namespace std;

ifstream fin("paznici.in");
ofstream fout("paznici.out");

vector<int> g[30];

bitset<30> used;

int r[30], l[30];

bool R[30], L[30];

bool pair_up(int node)
{
    if (used[node])
        return 0;

    used[node] = 1;

    for (auto i : g[node])
        if (!l[i])
        {
            l[i] = node;
            r[node] = i;
            return 1;
        }

    for (auto i : g[node])
        if (pair_up(l[i]))
        {
            l[i] = node;
            r[node] = i;
            return 1;
        }

    return 0;
}

void DFS(int node)
{
    for (auto i : g[node])
        if (!L[i])
        {
            L[i] = 1;
            R[l[i]] = 0;
            DFS(l[i]);
        }
}

int n, m;
char a;

int main()
{
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            fin >> a;
            if (a == '1')
                g[i].push_back(j);
        }

    bool ok = true;

    while (ok)
    {
        ok = false;
        used.reset();
        for (int i = 1; i <= n; ++i)
            if (!r[i])
                ok |= pair_up(i);
    }

    for (int i = 1; i <= n; ++i)
        if (r[i])
            R[i] = 1;

    for (int i = 1; i <= n; ++i)
        if (R[i] == 0)
            DFS(i);

    for (int i = 1; i <= n; ++i)
        if (R[i])
            fout << (char)('A' + i - 1);

    for (int i = 1; i <= m; ++i)
        if (L[i])
            fout << (char)('a' + i - 1);

    fout.close();
    return 0;
}

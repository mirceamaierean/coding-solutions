#include <fstream>
#include <vector>
#include <bitset>
using namespace std;

ifstream fin("cuplaj.in");
ofstream fout("cuplaj.out");

const int NMAX = 10005;

bitset<NMAX> used;

vector<int> g[NMAX];

int r[NMAX], l[NMAX], n, m, e, x, y;

bool pair_up(int node)
{
    if (used[node])
        return 0;

    used[node] = 1;

    for (size_t i = 0; i < g[node].size(); ++i)
    {
        int y = g[node][i];
        if (!l[y] || pair_up(l[y]))
        {
            l[y] = node;
            r[node] = y;
            return 1;
        }
    }
    return 0;
}

int main()
{
    fin >> n >> m >> e;
    for (int i = 1; i <= e; ++i)
    {
        fin >> x >> y;
        g[x].push_back(y);
    }
    int cnt = 0;
    for (bool ok = true; ok;)
    {
        ok = 0;
        used.reset();
        for (int i = 1; i <= n; ++i)
            if (!r[i] && pair_up(i))
            {
                ++cnt;
                ok = 1;
            }
    }

    fout << cnt << "\n";
    for (int i = 1; i <= n; ++i)
        if (r[i])
            fout << i << " " << r[i] << "\n";

    fout.close();
    return 0;
}

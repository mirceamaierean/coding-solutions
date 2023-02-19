#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

const int NMAX = 1e5 + 2;

vector<int> g[NMAX];
vector<pair<int, int>> c;

int n, m, x, y, cost[NMAX], i;

ifstream fin("srevni.in");
ofstream fout("srevni.out");

void DFS(int x)
{
    cost[x] = c[i].first;
    for (size_t j = 0; j < g[x].size(); ++j)
        if (cost[g[x][j]] == -1)
            DFS(g[x][j]);
}

int main()
{
    fin >> n >> m;
    c.resize(n);

    for (i = 0; i < n; ++i)
    {
        fin >> c[i].first;
        c[i].second = i + 1;
        cost[i + 1] = -1;
    }

    while (m--)
    {
        fin >> x >> y;
        g[y].push_back(x);
    }

    sort(c.begin(), c.end());

    for (i = 0; i < n; ++i)
    {
        x = c[i].second;
        if (cost[x] == -1)
        {
            DFS(x);
        }
    }

    for (int i = 1; i <= n; ++i)
        fout << cost[i] << " ";

    return 0;
}

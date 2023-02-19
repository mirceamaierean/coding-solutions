#include <fstream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

const int NMAX = 50003;
const int oo = 0x3f3f3f3f3f;

int d[NMAX];

ifstream fin("bellmanford.in");
ofstream fout("bellmanford.out");

vector<pair<int, int>> g[NMAX];
int viz[NMAX];

int n, m;

queue<int> q;

inline bool Bellman()
{
    while (!q.empty())
    {
        int x = q.front();
        viz[x]++;
        q.pop();

        if (viz[x] >= n)
            return false;

        for (size_t i = 0; i < g[x].size(); ++i)
        {
            int v = g[x][i].second, j = g[x][i].first;
            if (d[x] + v < d[j])
            {
                d[j] = d[x] + v;
                q.push(j);
            }
        }
    }
    return true;
}

int main()
{
    fin >> n >> m;

    memset(d, oo, sizeof d);

    for (int i = 1; i <= m; ++i)
    {
        int x, y, cost;
        fin >> x >> y >> cost;
        g[x].push_back({y, cost});
    }

    d[1] = 0;
    q.push(1);

    if (Bellman())
    {
        for (int i = 2; i <= n; ++i)
            fout << d[i] << " ";
    }
    else
        fout << "Ciclu negativ!\n";

    return 0;
}

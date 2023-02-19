#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

ifstream fin("apm.in");
ofstream fout("apm.out");

typedef pair<int, int> p;

const int NMAX = 200002;
const int oo = 0x3f3f3f3f;

vector<p> g[NMAX];

int n, x, y, c, m, d[NMAX], t[NMAX], cost;

bitset<NMAX> used;

struct cmp
{
    bool operator()(const p &x, const p &y) const
    {
        return x.second > y.second;
    }
};

priority_queue<p, vector<p>, cmp> q;
int main()
{
    fin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        fin >> x >> y >> c;
        g[x].push_back({y, c});
        g[y].push_back({x, c});
    }
    fill(d + 2, d + n + 1, oo);

    q.push({1, 0});
    used[0] = 1;

    int vn = n;

    while (vn)
    {
        x = 0;
        while (used[x])
        {
            x = q.top().first;
            q.pop();
        }
        used[x] = 1;
        cost += d[x];
        --vn;
        vector<p>::iterator it = g[x].begin(), f = g[x].end();
        for (; it != f; ++it)
            if (it->second < d[it->first] && used[it->first] == 0)
            {
                t[it->first] = x;
                d[it->first] = it->second;
                q.push({it->first, it->second});
            }
    }

    fout << cost << "\n"
         << n - 1 << "\n";

    for (int i = 2; i <= n; ++i)
        fout << i << " " << t[i] << "\n";

    return 0;
}

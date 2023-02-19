#include <fstream>
#include <queue>
#include <bitset>
#include <vector>

using namespace std;

const int NMAX = 101;
const int oo = 0x3f3f3f3f;
int dist[NMAX];

ifstream fin("coach.in");
ofstream fout("coach.out");

bitset<NMAX> valid, used;

int t, n, m, val[NMAX], x, y, z;

typedef pair<int, int> p;

vector<p> g[NMAX];

bool Dijkstra(int node, int v1, int v2)
{
    priority_queue<p, vector<p>, greater<p>> q;
    q.push({0, node});

    used.reset();

    while (!q.empty())
    {
        p crt;
        do
        {
            crt = q.top();
            q.pop();
        } while (!q.empty() && used[crt.second] == 1);

        if (crt.first == t)
        {
            fout << node << " " << crt.second << " " << v1 << " " << v2 << "\n";
            return 1;
        }

        used[crt.second] = 1;

        for (auto i : g[crt.second])
            if (valid[i.first] && used[i.first] == 0)
                q.push({crt.first + i.second, i.first});
    }

    return 0;
}

bool solve(int x, int y)
{
    if (x > y)
        swap(x, y);
    valid.reset();

    for (int i = 1; i <= n; ++i)
        if (x <= val[i] && val[i] <= y)
            valid[i] = 1;

    for (int i = 1; i <= n; ++i)
        if (valid[i] == 1)
            if (Dijkstra(i, x, y))
                return 1;

    return 0;
}

int main()
{
    fin >> n >> m >> t;

    for (int i = 1; i <= n; ++i)
        fin >> val[i];

    for (int i = 1; i <= m; ++i)
    {
        fin >> x >> y >> z;
        g[x].push_back({y, z});
        g[y].push_back({x, z});
    }
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (solve(val[i], val[j]))
                return 0;

    return 0;
}

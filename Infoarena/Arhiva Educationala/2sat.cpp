#include <fstream>
#include <vector>
#include <bitset>
#include <stack>

std::ifstream fin("2sat.in");
std::ofstream fout("2sat.out");

const int NMAX = 2 * 1e5 + 2;

std::vector<int> g[NMAX], rg[NMAX];
std::bitset<NMAX> used, ans;
std::stack<int> topo;
bool not_ok;
int n, m, x, y;

inline int neg(int x)
{
    if (x <= n)
        return x + n;
    return x - n;
}

void DFS1(int node)
{
    used[node] = 1;
    for (auto &i : g[node])
        if (used[i] == 0)
            DFS1(i);
    topo.push(node);
}

void DFS2(int node)
{
    if (ans[node] == 1)
        not_ok = true;
    used[node] = 1;
    ans[neg(node)] = 1;
    for (auto &i : rg[node])
        if (used[i] == 0)
            DFS2(i);
}

int main()
{
    fin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        fin >> x >> y;
        if (x < 0)
            x = n - x;
        if (y < 0)
            y = n - y;
        int negx = neg(x), negy = neg(y);
        g[negx].push_back(y);
        g[negy].push_back(x);
        rg[x].push_back(negy);
        rg[y].push_back(negx);
    }

    for (int i = 1; i <= 2 * n; ++i)
        if (used[i] == 0)
            DFS1(i);

    used.reset();

    while (!topo.empty())
    {
        x = topo.top();
        topo.pop();
        if (used[x] == 0 && used[neg(x)] == 0)
            DFS2(x);
    }

    if (not_ok)
        fout << "-1\n";
    else
    {
        for (int i = 1; i <= n; ++i)
            fout << ans[i] << " ";
    }
    return 0;
}

#include <fstream>
#include <vector>
#include <bitset>
#include <stack>

std::ifstream fin("party.in");
std::ofstream fout("party.out");

const int NMAX = 500;

std::vector<int> g[NMAX], rg[NMAX];
std::bitset<NMAX> used, ans;
std::stack<int> topo;
bool not_ok;
int n, m, x, y, c;

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

void poz()
{
    if (c == 1)
        y += n;
    else if (c == 2)
        x += n;
    else if (c == 3)
    {
        x += n;
        y += n;
    }
}

int main()
{
    fin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        fin >> x >> y >> c;
        poz();
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

    int cnt(0);
    for (int i = 1; i <= n; ++i)
        if (ans[i])
            cnt++;
    fout << cnt << "\n";
    for (int i = 1; i <= n; ++i)
        if (ans[i])
            fout << i << "\n";

    return 0;
}

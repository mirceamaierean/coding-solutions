#include <fstream>
#include <vector>
using namespace std;

ifstream fin("lca.in");
ofstream fout("lca.out");

const int NMAX = 100005;
const int KMAX = 20;

int n, m, deep[NMAX], euler[2 * NMAX], k, euler_lvl[2 * NMAX];

int rmq[KMAX][2 * NMAX], lg[2 * NMAX], fst[NMAX];

vector<int> g[NMAX];

void DFS(int node)
{
    euler[++k] = node;
    euler_lvl[k] = deep[node];
    fst[node] = k;
    for (auto i : g[node])
    {
        deep[i] = deep[node] + 1;
        DFS(i);
        euler[++k] = node;
        euler_lvl[k] = deep[node];
    }
}

void RMQ()
{
    rmq[0][1] = 1;
    for (int i = 2; i <= k; ++i)
    {
        rmq[0][i] = i;
        lg[i] = lg[i >> 1] + 1;
    }
    for (int i = 1; (1 << i) <= k; ++i)
        for (int j = 1; j + (1 << i) - 1 <= k; ++j)
        {
            int ind1 = rmq[i - 1][j], ind2 = rmq[i - 1][(j + (1 << (i - 1)))];
            if (euler_lvl[ind1] > euler_lvl[ind2])
                rmq[i][j] = ind2;
            else
                rmq[i][j] = ind1;
        }
}

int lca(int x, int y)
{
    x = fst[x];
    y = fst[y];
    if (x > y)
        swap(x, y);
    int t = lg[y - x + 1];
    int ind1 = rmq[t][x], ind2 = rmq[t][y - (1 << t) + 1];
    if (euler_lvl[ind1] < euler_lvl[ind2])
        return euler[ind1];
    return euler[ind2];
}

int main()
{
    int x, y;
    fin >> n >> m;
    for (int i = 2; i <= n; ++i)
    {
        fin >> x;
        g[x].push_back(i);
    }
    deep[1] = 1;
    DFS(1);
    RMQ();
    while (m--)
    {
        fin >> x >> y;
        fout << lca(x, y) << "\n";
    }
    fout.close();
    return 0;
}

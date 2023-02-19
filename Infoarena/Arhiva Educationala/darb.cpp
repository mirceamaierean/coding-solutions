#include <fstream>
#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

const int NMAX = 1e5 + 2;

vector<int> g[NMAX];

bitset<NMAX> viz;

int x, y, n, darb, start;

void DFS(int x, int niv)
{
    if (niv > darb)
    {
        darb = niv;
        start = x;
    }
    viz[x] = 1;
    for (size_t i = 0; i < g[x].size(); ++i)
        if (viz[g[x][i]] == 0)
            DFS(g[x][i], niv + 1);
}

ifstream fin("darb.in");
ofstream fout("darb.out");

int main()
{
    fin >> n;
    for (int i = 1; i < n; ++i)
    {
        fin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    DFS(1, 1);
    viz.reset();
    darb = 0;
    DFS(start, 1);
    fout << darb << "\n";
    return 0;
}

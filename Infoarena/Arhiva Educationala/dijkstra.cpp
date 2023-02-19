#include <fstream>
#include <queue>
#include <vector>
#include <string.h>
#define NMAX 50005
#define oo (1 << 30)

using namespace std;

int n, m, d[NMAX];
bool InCoada[NMAX];

vector<pair<int, int>> G[NMAX];

ifstream fin("dijkstra.in");
ofstream fout("dijkstra.out");

struct compara
{
    bool operator()(int x, int y)
    {
        return d[x] > d[y];
    }
};

priority_queue<int, vector<int>, compara> coada;

void Dijkstra(int start)
{
    for (int i = 1; i <= n; ++i)
        d[i] = oo;

    d[start] = 0;

    coada.push(start);
    InCoada[start] = true;

    while (!coada.empty())
    {
        int curent = coada.top();
        coada.pop();
        InCoada[curent] = false;
        for (size_t i = 0; i < G[curent].size(); ++i)
        {
            int vecin = G[curent][i].first, cost = G[curent][i].second;
            if (d[curent] + cost < d[vecin])
            {
                d[vecin] = d[curent] + cost;
                if (InCoada[vecin] == false)
                {
                    coada.push(vecin);
                    InCoada[vecin] = true;
                }
            }
        }
    }
}
void Solve()
{
    fin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int x, y, c;
        fin >> x >> y >> c;
        G[x].push_back(make_pair(y, c));
    }
    Dijkstra(1);
    for (int i = 2; i <= n; ++i)
        if (d[i] == oo)
            fout << "0 ";
        else
            fout << d[i] << " ";
}
int main()
{
    Solve();
    return 0;
}

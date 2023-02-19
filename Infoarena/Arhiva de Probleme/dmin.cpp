#include <fstream>
#include <queue>
#include <cmath>
#include <vector>
#include <bitset>
#include <string.h>
using namespace std;

const double eps = 1e-10;
const int NMAX = 1503;
const int MOD = 104659;
const int oo = 0x3f3f3f3f;
bitset<NMAX> viz;

ifstream fin("dmin.in");
ofstream fout("dmin.out");

int n, m, x, y, r[NMAX];
double cost;

vector<double> d(NMAX, oo);

inline bool egal(double a, double b)
{
    return (abs(a - b) <= eps);
}

vector<pair<int, double>> g[NMAX];
queue<int> q;

void BellmanFord()
{
    q.push(1);
    d[1] = 0;
    r[1] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        viz[x] = 0;
        for (size_t i = 0; i < g[x].size(); ++i)
        {
            int nod = g[x][i].first;
            if (egal(d[x] + g[x][i].second, d[nod]))
            {
                r[nod] += r[x];
                if (r[nod] > MOD)
                    r[nod] -= MOD;
            }
            else if (d[x] + g[x][i].second < d[nod])
            {
                d[nod] = d[x] + g[x][i].second;
                r[nod] = r[x];
                if (viz[nod] == 0)
                {
                    viz[nod] = 1;
                    q.push(nod);
                }
            }
        }
    }
}

int main()
{
    fin >> n >> m;
    while (m--)
    {
        fin >> x >> y >> cost;
        cost = log(cost);
        g[x].push_back({y, cost});
    }
    BellmanFord();
    for (int i = 2; i <= n; ++i)
        fout << r[i] << " ";
    return 0;
}

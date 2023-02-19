#include <fstream>
#include <vector>
#include <queue>
#include <string.h>
#pragma warning(disable : 4996)

using namespace std;

const int NMAX = 36003;
const int oo = 0x3f3f3f;

int d[NMAX], c[NMAX];

class InParser
{
private:
    FILE *fin;
    char *buff;
    int sp;
    char read()
    {
        ++sp;
        if (sp == 4096)
        {
            sp = 0;
            fread(buff, 1, 4096, fin);
        }
        return buff[sp];
    }

public:
    InParser(const char *nume)
    {
        sp = 4095;
        buff = new char[4096];
        fin = fopen(nume, "r");
    }
    InParser &operator>>(int &n)
    {
        char c;
        n = 0;
        while (!isdigit(c = read()))
            ;
        n = c - '0';
        while (isdigit(c = read()))
            n = n * 10 + c - '0';
        return *this;
    }
};

InParser fin("catun.in");
ofstream fout("catun.out");

vector<pair<int, int>> g[NMAX];

int n, m, k;

queue<int> q;
int a;
void Dijkstra()
{
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (size_t i = 0; i < g[x].size(); ++i)
        {
            int v = g[x][i].second, j = g[x][i].first;
            if (d[x] + v < d[j] || (d[x] + v == d[j] && c[x] < c[j]))
            {
                d[j] = d[x] + v;
                c[j] = c[x];
                q.push(j);
            }
        }
    }
}

int main()
{
    fin >> n >> m >> k;

    memset(d, oo, sizeof d);

    for (int i = 1; i <= k; ++i)
    {
        fin >> a;
        c[a] = a;
        q.push(a);
        d[a] = 0;
    }

    for (int i = 1; i <= m; ++i)
    {
        int x, y, cost;
        fin >> x >> y >> cost;
        g[x].push_back({y, cost});
        g[y].push_back({x, cost});
    }

    Dijkstra();

    for (int i = 1; i <= n; ++i)
    {
        if (c[i] == i)
            fout << "0 ";
        else
            fout << c[i] << " ";
    }
    return 0;
}

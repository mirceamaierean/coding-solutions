#include <fstream>
#include <queue>
#include <vector>
#include <string.h>
#include <bitset>
using namespace std;

const int NMAX = 50005;

const long long oo = 0x3f3f3f3f3f3f;

int n, m, x, y, c;
long long d[NMAX], sol[NMAX];
bitset<NMAX> viz;

vector<pair<int, int>> G[NMAX];

class InParser
{
#pragma warning(disable : 4996)
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
        while (!isdigit(c = read()))
            ;
        n = c - '0';
        while (isdigit(c = read()))
            n = n * 10 + c - '0';
        return *this;
    }
    InParser &operator>>(long long &n)
    {
        char c;
        while (!isdigit(c = read()))
            ;
        n = c - '0';
        while (isdigit(c = read()))
            n = n * 10 + c - '0';
        return *this;
    }
};
InParser fin("distante.in");
ofstream fout("distante.out");

struct cmp
{
    bool operator()(int x, int y)
    {
        return d[x] > d[y];
    }
};

priority_queue<int, vector<int>, cmp> q;

void Dijkstra(int start)
{
    memset(d, oo, sizeof d);

    viz.reset();
    q.push(start);
    viz[start] = 1;

    d[start] = 0;

    while (!q.empty())
    {
        x = q.top();

        q.pop();

        viz[x] = 0;

        for (size_t i = 0; i < G[x].size(); ++i)
        {
            y = G[x][i].first, c = G[x][i].second;
            if (d[x] + c < d[y])
            {
                d[y] = d[x] + c;
                if (viz[y] == 0)
                {
                    q.push(y);
                    viz[y] = true;
                }
            }
        }
    }
}

int s;

bool Solve()
{
    fin >> n >> m >> s;

    for (int i = 1; i <= n; ++i)
    {
        fin >> sol[i];
        G[i].clear();
    }

    for (int i = 1; i <= m; ++i)
    {
        fin >> x >> y >> c;
        G[x].push_back(make_pair(y, c));
        G[y].push_back(make_pair(x, c));
    }

    Dijkstra(s);

    for (int i = 1; i <= n; ++i)
        if (d[i] != sol[i])
            return 0;
    return 1;
}

int t;

int main()
{
    fin >> t;
    while (t--)
    {
        if (Solve())
            fout << "DA\n";
        else
            fout << "NU\n";
    }
    return 0;
}

#include <fstream>
#include <vector>
#include <queue>
#pragma warning(disable : 4996)
using namespace std;

typedef pair<int, int> p;

const int NMAX = 3 * 1e4 + 2;

class parsare
{
private:
    FILE *fin;
    int sp;
    char *buff;
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
    parsare(const char *nume)
    {
        sp = 4095;
        fin = fopen(nume, "r");
        buff = new char[4096];
    }
    parsare &operator>>(int &n)
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

parsare fin("sate.in");
ofstream fout("sate.out");

vector<p> g[NMAX];
int dist[NMAX], n, m, x, y, d, a, b;

queue<int> q;

void solve()
{
    while (!q.empty())
    {
        x = q.front();
        q.pop();
        if (x == b)
        {
            fout << dist[b] << "\n";
            return;
        }
        vector<p>::iterator it = g[x].begin(), f = g[x].end();
        for (; it != f; ++it)
        {
            if (dist[it->first] == -1)
            {
                dist[it->first] = dist[x] + it->second;
                q.push(it->first);
            }
        }
    }
}

int main()
{
    fin >> n >> m >> a >> b;
    for (int i = 1; i <= m; ++i)
    {
        fin >> x >> y >> d;
        dist[x] = -1;
        dist[y] = -1;
        g[x].push_back({y, d});
        g[y].push_back({x, -d});
    }
    dist[a] = 0;
    q.push(a);
    solve();
    return 0;
}

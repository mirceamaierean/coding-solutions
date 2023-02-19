#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <bitset>
#include <string.h>
using namespace std;

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
};
InParser fin("pitici.in");
ofstream fout("pitici.out");

const int NMAX = 1020;
const int oo = 0x3f3f3f;

int n, m, k, x, y, c, dp[NMAX][NMAX], cost[NMAX], ind[NMAX];

typedef pair<int, int> p;

vector<p> g[NMAX];

vector<int> pit;

bitset<NMAX> viz;

struct cmp
{
    inline bool operator()(int a, int b)
    {
        return cost[a] > cost[b];
    }
};

void solve(int x)
{
    viz[x] = 1;
    if (x == n)
    {
        dp[x][0] = 0;
        return;
    }
    if (g[x].empty())
        return;

    priority_queue<int, vector<int>, cmp> q;

    for (auto i : g[x])
    {
        if (!viz[i.first])
            solve(i.first);

        cost[i.first] = i.second + dp[i.first][0], ind[i.first] = 0;
        q.push(i.first);
    }
    for (int i = 0; i < k; ++i)
    {
        int y = q.top();
        q.pop();
        dp[x][i] = cost[y];
        cost[y] -= dp[y][ind[y]];
        ++ind[y];
        cost[y] += dp[y][ind[y]];
        q.push(y);
    }
}

int main()
{
    fin >> n >> m >> k;

    for (int i = 1; i <= m; ++i)
    {
        fin >> x >> y >> c;
        g[x].push_back({y, c});
    }

    memset(dp, oo, sizeof dp);

    solve(1);

    for (int i = 0; i < k; ++i)
        fout << dp[1][i] << " ";

    fout.close();
    return 0;
}

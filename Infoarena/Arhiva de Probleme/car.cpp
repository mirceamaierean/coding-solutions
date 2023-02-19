#include <fstream>
#include <queue>
#include <vector>
#include <bitset>
#include <cmath>
#pragma warning(disable : 4996)

using namespace std;

const int NMAX = 505;
const int oo = 0x3f3f3f3f;
bitset<NMAX> a[NMAX];

struct car
{
    int x, y, c, dir;
};

int cost[8][NMAX][NMAX], mini = oo;

queue<car> q1, q2;

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
        fin = fopen(nume, "r");
        buff = new char[4096];
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

InParser fin("car.in");
ofstream fout("car.out");

int n, m, t, sx, sy, fx, fy;

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

inline bool ok(car b)
{
    return b.x && b.y && b.x <= n && b.y <= m && a[b.x][b.y] == 0;
}

int solve()
{
    car u, v;
    for (int i = 0; i < 8; ++i)
        q1.push({sx, sy, 0, i});
    while (!q1.empty())
    {
        while (!q1.empty())
        {
            u = q1.front();
            q1.pop();
            v = u;
            v.x += dx[v.dir];
            v.y += dy[v.dir];
            if (ok(v) && cost[v.dir][v.x][v.y] > v.c)
            {
                q1.push(v);
                cost[v.dir][v.x][v.y] = v.c;
            }
            v = u;
            ++v.c;
            ++v.dir;
            if (v.dir == 8)
                v.dir = 0;
            if (ok(v) && cost[v.dir][v.x][v.y] > v.c)
            {
                q2.push(v);
                cost[v.dir][v.x][v.y] = v.c;
            }
            v.dir = u.dir - 1;
            if (v.dir < 0)
                v.dir = 7;
            if (ok(v) && cost[v.dir][v.x][v.y] > v.c)
            {
                q2.push(v);
                cost[v.dir][v.x][v.y] = v.c;
            }
        }
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }
    for (int i = 0; i < 8; ++i)
        if (cost[i][fx][fy] < mini)
            mini = cost[i][fx][fy];
    if (mini == oo)
        mini = -1;
    return mini;
}

int main()
{
    fin >> n >> m;
    fin >> sx >> sy >> fx >> fy;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            fin >> t;
            a[i][j] = t;
            for (t = 0; t < 8; ++t)
                cost[t][i][j] = oo;
        }

    if (a[sx][sy] == 1 || a[fx][fy] == 1)
    {
        fout << "-1\n";
        return 0;
    }

    for (int i = 0; i < 8; ++i)
        cost[i][sx][sy] = 0;

    fout << solve() << "\n";

    return 0;
}

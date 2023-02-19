#include <fstream>
#include <bitset>
#include <queue>
#include <vector>
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
InParser fin("lanterna.in");
ofstream fout("lanterna.out");

const int NMAX = 52;
const int LMAX = 1002;
const int oo = 0x3f3f3f3f;
vector<int> v[NMAX];

bitset<NMAX> recharge;

int mini, w[NMAX][NMAX], n, m, k, a, b, t[NMAX][NMAX], d[NMAX][LMAX], t_min;

struct lanterna
{
    int nod, w;
};

bool check(int l)
{
    memset(d, oo, sizeof d);

    d[1][l] = 0;

    queue<lanterna> q;

    q.push({1, l});
    while (!q.empty())
    {
        lanterna x = q.front();
        q.pop();

        int dist = d[x.nod][x.w];

        if (recharge[x.nod])
            x.w = l;

        for (size_t i = 0; i < v[x.nod].size(); ++i)
        {
            int y = v[x.nod][i], ind = x.w - w[x.nod][y];
            if (ind >= 0 && dist + t[x.nod][y] < d[y][ind])
            {
                d[y][ind] = dist + t[x.nod][y];
                q.push({y, ind});
            }
        }
    }
    mini = oo;
    for (int i = 0; i <= l; ++i)
        mini = min(mini, d[n][i]);
    return mini == t_min;
}

int binary_search()
{
    int r = k, st = 1, dr = k;
    while (st <= dr)
    {
        int mij = ((st + dr) >> 1);
        if (check(mij))
        {
            if (mij < r)
                r = mij;
            dr = mij - 1;
        }
        else
            st = mij + 1;
    }
    return r;
}

int main()
{
    fin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        fin >> m;
        recharge[i] = m;
    }
    fin >> m;
    while (m--)
    {
        fin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        fin >> t[a][b] >> w[a][b];
        t[b][a] = t[a][b];
        w[b][a] = w[a][b];
    }

    check(k);

    t_min = mini;

    fout << t_min << " " << binary_search();

    return 0;
}

#include <fstream>
#include <algorithm>
#include <vector>
#include <bitset>

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

InParser fin("concurs.in");
std::ofstream fout("concurs.out");

const int NMAX = 32001;
const int KMAX = 17;

int a[NMAX], n, m, root, x, y, maxi;

std::vector<int> v[NMAX];

int deep[NMAX], euler[2 * NMAX], k, euler_lvl[2 * NMAX];

int rmq[KMAX][2 * NMAX], lg[2 * NMAX], fst[NMAX];

void DFS(int node)
{
    euler[++k] = node;
    euler_lvl[k] = deep[node];
    fst[node] = k;
    for (auto i : v[node])
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
            int ind1 = rmq[i - 1][j], ind2 = rmq[i - 1][j + (1 << i - 1)];
            if (euler_lvl[ind1] > euler_lvl[ind2])
                rmq[i][j] = ind2;
            else
                rmq[i][j] = ind1;
        }
}

int LCA(int x, int y)
{
    x = fst[x];
    y = fst[y];
    if (x > y)
        std::swap(x, y);
    int t = lg[y - x + 1];
    int ind1 = rmq[t][x], ind2 = rmq[t][y - (1 << t) + 1];
    if (euler_lvl[ind1] < euler_lvl[ind2])
        return euler[ind1];
    return euler[ind2];
}

void solve()
{
    deep[root] = 1;
    DFS(root);
    RMQ();
}

int main()
{
    fin >> n >> m;
    root = (n * (n + 1)) >> 1;
    for (int i = 1; i <= n; ++i)
        fin >> a[i];
    for (int i = 1; i < n; ++i)
    {
        fin >> x >> y;
        v[x].push_back(y);
        root -= y;
    }

    solve();

    for (int i = 1; i <= m; ++i)
    {
        int x, y, maxi;
        fin >> x >> y;
        maxi = a[LCA(x, y)];
        if (maxi > ::maxi)
        {
            ::maxi = maxi;
            ::x = x;
            ::y = y;
        }
        else if (maxi == ::maxi)
        {
            if (x < ::x || (x == ::x && y < ::y))
            {
                ::x = x;
                ::y = y;
            }
        }
    }

    fout << ::maxi << " " << ::x << " " << ::y << "\n";

    fout.close();
    return 0;
}

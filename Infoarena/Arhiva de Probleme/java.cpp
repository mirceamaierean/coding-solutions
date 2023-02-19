#include <fstream>
#include <vector>
#include <string.h>
#include <bitset>
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

InParser fin("java.in");
ofstream fout("java.out");

const int NMAX = 10003;

int n, m, e, x, y;

bitset<NMAX> used;

vector<int> v[NMAX];
vector<int> r;
vector<int> l;

bool pair_up(int node)
{
    if (used[node])
        return 0;
    used[node] = 1;
    for (auto i : v[node])
    {
        if (!l[i])
        {
            l[i] = node;
            r[node] = i;
            return 1;
        }
    }
    for (auto i : v[node])
    {
        if (pair_up(l[i]))
        {
            l[i] = node;
            r[node] = i;
            return 1;
        }
    }
    return 0;
}

int main()
{
    int t;

    fin >> t;

    while (t--)
    {
        fin >> n >> m >> e;

        r = vector<int>(NMAX, 0);
        l = vector<int>(NMAX, 0);

        for (int i = 1; i <= n; ++i)
            v[i].clear();

        for (int i = 1; i <= e; ++i)
        {
            fin >> x >> y;
            v[x].push_back(y);
        }
        bool ok = true;
        int cnt = 0;
        while (ok)
        {
            ok = false;
            used.reset();
            for (int i = 1; i <= n; ++i)
                if (!r[i] && pair_up(i))
                {
                    ok = true;
                    cnt++;
                }
        }
        fout << cnt << "\n";
    }

    fout.close();
    return 0;
}

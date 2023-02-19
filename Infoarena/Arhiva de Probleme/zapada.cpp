#include <fstream>
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

InParser fin("zapada.in");
std::ofstream fout("zapada.out");

const int NMAX = 1e5 + 1;

std::bitset<NMAX> viz;
std::vector<int> g[NMAX];

int ciup[NMAX], n, m, x, y, st, cnt;

void DFS(int x)
{
    viz[x] = 1;

    for (auto i : g[x])
        if (!viz[i])
            DFS(i);

    st = x;
}

void solve(int x)
{
    ciup[x] = ++cnt;

    for (auto i : g[x])

        if (!ciup[i])
            solve(i);
}

void print()
{
    for (int i = 1; i <= n; ++i)
        fout << ciup[i] << "\n";
}

void init()
{
    fin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        fin >> x >> y;
        g[y].push_back(x);
    }

    for (int i = 1; i <= n; ++i)
        if (!viz[i])
            DFS(i);
}
int main()
{
    init();
    solve(st);
    print();
    fout.close();
    return 0;
}

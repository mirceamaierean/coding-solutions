#include <fstream>
#include <bitset>
#include <vector>
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
InParser fin("maimute.in");
ofstream fout("maimute.out");

const int NMAX = 1e5 + 2;

bitset<NMAX> viz;

vector<int> v[NMAX];

int m, n, x, y, ind, f[NMAX], s[NMAX];

void DFS(int nod)
{
    f[nod] = ++ind;

    viz[nod] = 1;

    for (size_t i = 0; i < v[nod].size(); ++i)
        if (viz[v[nod][i]] == 0)
            DFS(v[nod][i]);

    s[nod] = ++ind;
}

int main()
{
    fin >> n;
    for (int i = 1; i < n; ++i)
    {
        fin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    DFS(1);
    fin >> n;
    while (n--)
    {
        fin >> x >> y;
        if ((f[x] < f[y] && s[y] < s[x]) || (f[y] < f[x] && s[x] < s[y]))
            fout << "DA\n";
        else
            fout << "NU\n";
    }
    fout.close();
    return 0;
}

#include <fstream>
#include <limits.h>
using namespace std;

class InParser
{
private:
    FILE *fin;
    char *buff;
    int sp;
    char read_ch()
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
        fin = fopen(nume, "r");
        buff = new char[4096]();
        sp = 4095;
    }
    InParser &operator>>(int &n)
    {
        char c;

        while (!isdigit(c = read_ch()) && c != '-')
            ;
        int sgn = 1;
        if (c == '-')
        {
            n = 0;
            sgn = -1;
        }
        else
            n = c - '0';

        while (isdigit(c = read_ch()))
            n = n * 10 + c - '0';

        n *= sgn;

        return *this;
    }
};

ifstream fin("sequencequery.in");
ofstream fout("sequencequery.out");

const int MAXN = 100001;

struct ai
{
    long long suma_stanga, suma_dreapta, suma_max, suma;
};

ai a[4 * MAXN];

int val, p, n, q;

long long maxi(long long a, long long b)
{
    return (a > b) ? a : b;
}

ai merge(ai stanga, ai dreapta)
{
    ai tree;
    tree.suma = stanga.suma + dreapta.suma;
    tree.suma_stanga = maxi(stanga.suma_stanga, stanga.suma + dreapta.suma_stanga);
    tree.suma_dreapta = maxi(dreapta.suma_dreapta, dreapta.suma + stanga.suma_dreapta);
    tree.suma_max = maxi(maxi(stanga.suma_max, dreapta.suma_max), stanga.suma_dreapta + dreapta.suma_stanga);
    return tree;
}

void build(int nod, int stanga, int dreapta)
{
    if (stanga == dreapta)
    {
        fin >> val;
        a[nod].suma_stanga = a[nod].suma_dreapta = a[nod].suma_max = a[nod].suma = val;
    }
    else
    {
        int mij = (stanga + dreapta) / 2;
        build(2 * nod, stanga, mij);
        build(2 * nod + 1, mij + 1, dreapta);
        a[nod] = merge(a[2 * nod], a[2 * nod + 1]);
    }
}

int L, R;

ai query(int nod, int stanga, int dreapta)
{
    if (stanga > dreapta || stanga > R || dreapta < L)
    {
        ai t;
        t.suma_stanga = t.suma_dreapta = t.suma_max = t.suma = -MAXN;
        return t;
    }

    if (L <= stanga && dreapta <= R)
        return a[nod];

    int mij = (stanga + dreapta) / 2;

    ai left = query(2 * nod, stanga, mij), right = query(2 * nod + 1, mij + 1, dreapta);

    return merge(left, right);
}

int main()
{
    fin >> n >> q;

    build(1, 1, n);

    while (q--)
    {
        fin >> L >> R;
        fout << query(1, 1, n).suma_max << "\n";
    }
    return 0;
}

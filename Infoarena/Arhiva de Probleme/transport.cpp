#include <fstream>
#include <vector>
using namespace std;

ifstream fin("transport.in");
ofstream fout("transport.out");

vector<int> v;

int rez, n, k, s, d, c;

int b_search(int st, int dr, int val)
{
    int rez = 0;
    while (st <= dr)
    {
        int mij = ((st + dr) >> 1);
        if (v[mij] - v[c] <= val)
        {
            rez = mij;
            st = mij + 1;
        }
        else
            dr = mij - 1;
    }
    return rez;
}

bool check(int x)
{
    int ant = 1;
    c = 0;
    for (int i = 1; i <= k; ++i)
    {
        ant = b_search(ant, n, x);
        c = ant;
        if (ant == 0)
            return 0;
        if (ant == n)
            return 1;
        ++ant;
    }
    return 0;
}

int main()
{
    fin >> n >> k;
    v.resize(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        fin >> v[i];
        if (v[i] > s)
            s = v[i];
        v[i] += v[i - 1];
    }

    d = v[n];
    rez = v[n];
    while (s <= d)
    {
        int mij = ((s + d) >> 1);
        if (check(mij))
        {
            if (mij < rez)
                rez = mij;
            d = mij - 1;
        }
        else
            s = mij + 1;
    }

    fout << rez << "\n";

    return 0;
}

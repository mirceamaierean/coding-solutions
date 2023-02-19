
#include <fstream>
#include <vector>
#include <iostream>
#include <map>
#include <string.h>
using namespace std;

ifstream fin("triunghi.in");
ofstream fout("triunghi.out");

const int NMAX = 1e6 + 2;

struct trg
{
    bool se_poate;
    long long tata;
};

long long fr[20][20], s, put;
int n;
long long a[20][20];

trg v[NMAX];
map<long long, int> h;

int main()
{
    fin >> n >> s;

    put = 1LL << (n - 1);

    for (long long i = 1; i <= n; ++i)
    {
        a[n][i] = 1;
        s -= i * put;
        put >>= 1;
        if (s < 0)
        {
            fout << "imposibil";
            return 0;
        }
    }

    int m = (n >> 1) + (n & 1);

    v[0].se_poate = 1;

    fr[1][1] = 1;

    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i; j++)
            fr[i][j] = 1 + fr[i - 1][j - 1] + fr[i - 1][j];

    for (int i = 1; i <= m; ++i)
    {
        if (fr[n][i] <= s)
        {
            v[fr[n][i]].se_poate = 1;
            h.insert({fr[n][i], i});
        }
    }
    for (int i = 1; i <= s; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            int ind = i - fr[n][j];
            if (ind >= 0 && v[ind].se_poate)
            {
                v[i].se_poate = 1;
                if (v[i].tata == 0)
                {
                    v[i].tata = ind;
                    break;
                }
            }
        }
    }

    if (v[s].se_poate == 0)
        fout << "imposibil";

    else
    {
        while (s != v[s].tata)
        {
            int val = h[s - v[s].tata];
            ++a[n][val];
            s = v[s].tata;
        }

        for (int i = n - 1; i; --i)
        {
            for (int j = 1; j <= i; ++j)
                a[i][j] = a[i + 1][j] + a[i + 1][j + 1];
        }

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= i; ++j)
                fout << a[i][j] << " ";
            fout << "\n";
        }
    }
    return 0;
}
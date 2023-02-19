#include <fstream>
#include <bitset>
#include <string.h>
#include <algorithm>
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
InParser fin("puteri.in");
ofstream fout("puteri.out");

const int PMAX = 65;
const int NMAX = 134;
const int MAXN = 1e5 + 2;

bitset<NMAX> ciur;

int sgn[NMAX], n, a[MAXN], b[MAXN], c[MAXN], m[MAXN], fr[PMAX][PMAX][PMAX];

long long cnt;

long long solve(int mod)
{
    int i_a, i_b, i_c;
    long long s = 0;
    memset(fr, 0, sizeof fr);
    for (int i = 0; i <= 128; ++i)
        m[i] = i % mod;
    for (int i = 1; i <= n; ++i)
    {
        i_a = m[mod - m[a[i]]];
        i_b = m[mod - m[b[i]]];
        i_c = m[mod - m[c[i]]];
        if (i_a <= 64 && i_b <= 64 && i_c <= 64)
            s += fr[i_a][i_b][i_c];
        ++fr[m[a[i]]][m[b[i]]][m[c[i]]];
    }
    return s;
}

int main()
{
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> a[i] >> b[i] >> c[i];

    fill(sgn + 1, sgn + 128 + 1, 1);

    for (int i = 2; i <= 128; ++i)
    {
        if (!ciur[i])
        {
            for (int j = i; j <= 128; j += i)
            {
                sgn[j] *= -1;
                ciur[j] = 1;
            }
            for (int j = i * i; j <= 128; j += i * i)
                sgn[j] = 0;
        }
        if (sgn[i])
            cnt -= sgn[i] * solve(i);
    }
    fout << cnt << "\n";
    fout.close();
    return 0;
}

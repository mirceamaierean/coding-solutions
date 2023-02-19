#include <fstream>
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
InParser fin("iepuri.in");
ofstream fout("iepuri.out");

const int MOD = 666013;

long long p[3][3], q[3][3], r[3][3];
int x, y, z, a, b, c, n, t;

void exp_mat()
{
    memset(p, 0, sizeof p);
    memset(q, 0, sizeof q);
    memset(r, 0, sizeof r);

    p[0][1] = p[1][2] = 1;
    p[0][0] = a;
    p[1][0] = b;
    p[2][0] = c;

    q[0][0] = q[1][1] = q[2][2] = 1;

    n -= 2;

    while (n)
    {
        if (n & 1)
        {
            for (int i = 0; i < 3; ++i)
                for (int j = 0; j < 3; ++j)
                {
                    r[i][j] = 0;
                    for (int l = 0; l < 3; ++l)
                    {
                        r[i][j] += q[i][l] * p[l][j];
                        r[i][j] %= MOD;
                    }
                }
            for (int i = 0; i < 3; ++i)
                for (int j = 0; j < 3; ++j)
                    q[i][j] = r[i][j];
        }
        n >>= 1;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
            {
                r[i][j] = 0;
                for (int l = 0; l < 3; ++l)
                {
                    r[i][j] += p[i][l] * p[l][j];
                    r[i][j] %= MOD;
                }
            }
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                p[i][j] = r[i][j];
    }
    long long val = 1LL * z * q[0][0] + 1LL * y * q[1][0] + 1LL * x * q[2][0];
    fout << val % MOD << "\n";
}

int main()
{
    fin >> t;
    while (t--)
    {
        fin >> x >> y >> z >> a >> b >> c >> n;
        exp_mat();
    }
    fout.close();
    return 0;
}

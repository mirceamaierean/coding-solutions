#include <fstream>
#include <algorithm>
#include <string.h>

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
        int sgn = 1;
        char c;
        while (!isdigit(c = read()) && c != '-')
            ;
        if (c == '-')
        {
            n = 0;
            sgn = -1;
        }
        else
            n = c - '0';
        while (isdigit(c = read()))
            n = n * 10 + c - '0';
        n *= sgn;
        return *this;
    }
};

InParser fin("coins.in");
std::ofstream fout("coins.out");

const int NMAX = 22;
char a[1 << NMAX];

void init()
{
    memset(a, -1, sizeof a);
    for (int i = 1; i <= 22; ++i)
        a[(1 << i) - 1] = 1;
}

bool ok(int mask)
{
    if (a[mask] != -1)
        return a[mask];
    int ant = -1;
    int _ok = 1;
    for (int i = 0; i < 22; ++i)
        if (mask & (1 << i))
        {
            if (ant != -1)
            {
                int new_mask = mask ^ (1 << i) | (1 << ant);
                _ok &= ok(new_mask);
            }
        }
        else
            ant = i;

    _ok ^= 1;
    a[mask] = _ok;
    return _ok;
}

int n, x, ans(0), s[22];

int main()
{
    init();
    fin >> n;
    while (n--)
    {
        int mask(0), coins(0);

        for (int i = 21; i >= 0; --i)
            fin >> s[i];
        for (int i = 0; i < 22; ++i)
        {
            mask <<= 1;
            if (s[i])
            {
                mask |= 1;
                ++coins;
            }
        }

        if (ok(mask))
            ans += coins;
    }

    fout << ans << "\n";

    fout.close();
    return 0;
}

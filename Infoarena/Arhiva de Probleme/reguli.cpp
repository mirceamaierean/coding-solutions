#include <fstream>

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
    InParser(const char *name)
    {
        fin = fopen(name, "r");
        buff = new char[4096];
        sp = 4095;
    }
    template <class T>
    InParser &operator>>(T &n)
    {
        T sgn = 1;
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

InParser fin("reguli.in");
std::ofstream fout("reguli.out");

const int NMAX = 5e5 + 1;

int pr[NMAX], n;
long long diff[NMAX], a, b;

void prefix()
{
    int k = 0;
    for (int i = 2; i <= n; ++i)
    {
        while (k && diff[k + 1] != diff[i])
            k = pr[k];

        if (diff[k + 1] == diff[i])
            ++k;

        pr[i] = k;
    }
}

int main()
{
    fin >> n >> a;

    for (int i = 1; i < n; ++i)
    {
        fin >> b;
        diff[i] = b - a;
        a = b;
    }

    --n;

    prefix();

    n -= pr[n];

    fout << n << '\n';
    for (int i = 1; i <= n; ++i)
        fout << diff[i] << "\n";

    fout.close();
    return 0;
}

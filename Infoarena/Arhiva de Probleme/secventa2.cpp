#include <fstream>
#include <vector>
#pragma warning(disable : 4996)
using namespace std;

const int oo = 0x3f3f3f3f;

class InParser
{
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
        int sgn = 1;
        while (!isdigit(c = read()) && c != '-')
            ;
        if (c == '-')
        {
            sgn = -1;
            n = 0;
        }
        else
            n = c - '0';
        while (isdigit(c = read()))
            n = n * 10 + c - '0';
        n *= sgn;
        return *this;
    }
};

InParser fin("secv2.in");
ofstream fout("secv2.out");

int n, k, s, f, mini, maxi, p;

vector<int> v;

int main()
{
    mini = oo;
    maxi = -mini;
    fin >> n >> k;
    v.resize(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        fin >> v[i];
        v[i] += v[i - 1];
    }

    for (int i = k; i <= n; ++i)
    {
        if (v[i - k] < mini)
        {
            mini = v[i - k];
            p = i - k + 1;
        }
        if (v[i] - mini > maxi)
        {
            maxi = v[i] - mini;
            s = p;
            f = i;
        }
    }
    fout << s << " " << f << " " << maxi << "\n";
    return 0;
}

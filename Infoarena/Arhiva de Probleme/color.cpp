#include <fstream>
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

InParser fin("color.in");
ofstream fout("color.out");

const int NMAX = 4001;

vector<int> v[NMAX];

int x, y, n, s;

long long cnt;

int main()
{
    fin >> n >> s;
    for (int i = 1; i <= s; ++i)
    {
        fin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    for (int i = 1; i <= n; ++i)
    {
        s = v[i].size();
        cnt += 1LL * s * (n - s - 1);
    }

    cnt >>= 1;

    fout << 1LL * n * (n - 1) * (n - 2) / 6 - cnt;

    return 0;
}

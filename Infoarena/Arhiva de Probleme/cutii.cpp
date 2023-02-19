#include <fstream>
#include <vector>
#define ub(x) x &(-x)
#define NMAX 3505
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

InParser fin("cutii.in");
ofstream fout("cutii.out");

int n, t, aib[NMAX][NMAX];

vector<pair<int, int>> v;

void update(int x, int y, int val)
{
    for (int i = x; i <= n; i += ub(i))
        for (int j = y; j <= n; j += ub(j))
            aib[i][j] = max(val, aib[i][j]);
}

int query(int x, int y)
{
    int val = 0;
    for (int i = x; i; i -= ub(i))
        for (int j = y; j; j -= ub(j))
            val = max(val, aib[i][j]);
    return val;
}

void clear(int x, int y)
{
    for (int i = x; i <= n; i += ub(i))
        for (int j = y; j <= n; j += ub(j))
            aib[i][j] = 0;
}

int main()
{
    fin >> n >> t;

    v.resize(n + 1);

    while (t--)
    {
        int maxi = 0, x, y, z;

        for (int i = 1; i <= n; ++i)
        {
            fin >> x >> y >> z;
            v[z] = make_pair(x, y);
        }

        for (int i = 1; i <= n; ++i)
        {
            int cnt = query(v[i].first - 1, v[i].second - 1) + 1;
            maxi = max(maxi, cnt);
            update(v[i].first, v[i].second, cnt);
        }

        fout << maxi << "\n";

        for (int i = 1; i <= n; ++i)
            clear(v[i].first, v[i].second);
    }
    return 0;
}

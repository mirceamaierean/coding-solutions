#include <fstream>
#include <algorithm>
#include <vector>

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
    InParser &operator>>(long long &n)
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

InParser fin("sume2.in");
std::ofstream fout("sume2.out");

std::vector<int> v;

int n, a;
long long k;

long long solve(int s)
{
    int dr = n;
    long long cnt(0);
    for (int i = 1; i <= n; ++i)
    {
        if (dr < i)
            break;

        while (i <= dr && v[i] + v[dr] > s)
            --dr;

        if (i <= dr)
            cnt += ((dr - i + 1) << 1) - 1;
    }
    return cnt;
}

int x;

int main()
{
    fin >> n >> k;

    v.push_back(0);

    for (int i = 1; i <= n; ++i)
    {
        fin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    int s(0), ant_s(0), r, max_s = v.back() << 1, min_s = v[1] << 1;

    while (min_s <= max_s)
    {
        s = (max_s + min_s) >> 1;

        long long cnt = solve(s);

        if (cnt < k)
            min_s = s + 1;

        else
        {
            ant_s = s;
            max_s = s - 1;
        }
    }

    fout << ant_s << "\n";

    fout.close();
    return 0;
}

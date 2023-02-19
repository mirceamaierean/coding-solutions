#include <fstream>
#include <queue>
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
    template <class T>
    InParser &operator>>(T &n)
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
InParser fin("lupu.in");
std::ofstream fout("lupu.out");

typedef std::pair<int, int> pii;

struct cmp1
{
    const inline bool operator()(const pii &a, const pii &b)
    {
        return a.first > b.first;
    }
};

std::priority_queue<pii, std::vector<pii>, cmp1> oi;

struct cmp2
{
    const inline bool operator()(const pii &a, const pii &b)
    {
        return a.second < b.second;
    }
};

std::priority_queue<pii, std::vector<pii>, cmp2> oiSortate;

pii a;

unsigned long long result;

int n, x, l;

int main()
{
    fin >> n >> x >> l;

    for (int i = 1; i <= n; ++i)
    {
        fin >> a.first >> a.second;
        oi.push(a);
    }

    for (int i = x % l; i <= x; i += l)
    {
        while (!oi.empty() && oi.top().first <= i)
        {
            oiSortate.push(oi.top());
            oi.pop();
        }
        if (!oiSortate.empty())
        {
            result += oiSortate.top().second;
            oiSortate.pop();
        }
    }

    fout << result << '\n';

    fout.close();
    return 0;
}

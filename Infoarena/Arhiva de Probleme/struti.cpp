#include <fstream>
#include <deque>
#include <algorithm>
#include <string.h>
#pragma warning(disable : 4996)
using namespace std;

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
        while (!isdigit(c = read()))
            ;
        n = c - '0';
        while (isdigit(c = read()))
            n = n * 10 + c - '0';
        return *this;
    }
};

InParser fin("struti.in");
ofstream fout("struti.out");

deque<int> minq;
deque<int> maxq;

const int NMAX = 1e3 + 2;

int a[NMAX][NMAX], cnt, n, m, min_crt, p;
int mini[NMAX][NMAX], maxi[NMAX][NMAX];

void solve(int x, int y)
{
    for (int i = 1; i <= n; ++i)
    {
        minq.clear();
        maxq.clear();
        for (int j = 1; j <= m; ++j)
        {
            while (!minq.empty() && a[i][minq.back()] >= a[i][j])
                minq.pop_back();

            minq.push_back(j);

            if (minq.front() <= j - x)
                minq.pop_front();

            mini[i][j] = a[i][minq.front()];

            while (!maxq.empty() && a[i][maxq.back()] <= a[i][j])
                maxq.pop_back();

            maxq.push_back(j);

            if (maxq.front() <= j - x)
                maxq.pop_front();

            maxi[i][j] = a[i][maxq.front()];
        }
    }
    for (int j = 1; j <= m; ++j)
    {
        minq.clear();
        maxq.clear();
        for (int i = 1; i <= n; ++i)
        {
            while (!minq.empty() && mini[minq.back()][j] >= mini[i][j])
                minq.pop_back();

            minq.push_back(i);

            if (minq.front() <= i - y)
                minq.pop_front();

            while (!maxq.empty() && maxi[maxq.back()][j] <= maxi[i][j])
                maxq.pop_back();

            maxq.push_back(i);

            if (maxq.front() <= i - y)
                maxq.pop_front();

            if (i >= y && j >= x)
            {
                int s = maxi[maxq.front()][j] - mini[minq.front()][j];
                if (s < min_crt)
                {
                    min_crt = s;
                    cnt = 1;
                }
                else if (s == min_crt)
                    ++cnt;
            }
        }
    }
}

int x, y;

int main()
{
    fin >> n >> m >> p;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            fin >> a[i][j];

    while (p--)
    {
        fin >> x >> y;
        min_crt = 10000;
        cnt = 0;
        solve(x, y);
        if (x != y)
            solve(y, x);
        fout << min_crt << " " << cnt << "\n";
    }
    return 0;
}

#include <fstream>
#include <deque>
using namespace std;

deque<pair<int, int>> q;

int maxi, p1;

class InParser
{
private:
    FILE *fin;
    char *buff;
    int sp;
    char read_ch()
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
        fin = fopen(nume, "r");
        buff = new char[4096]();
        sp = 4095;
    }

    InParser &operator>>(int &n)
    {
        char c;
        int sp = 1;
        while (!isdigit(c = read_ch()) && c != '-')
            ;

        if (c == '-')
        {
            n = 0;
            sp = -1;
        }
        else
            n = c - '0';

        while (isdigit(c = read_ch()))
            n = n * 10 + c - '0';

        n *= sp;

        return *this;
    }
};

InParser fin("secventa.in");
ofstream fout("secventa.out");

int main()
{
    int n, k, a;

    fin >> n >> k;

    p1 = k;

    for (int i = 1; i <= k; ++i)
    {
        fin >> a;
        while (q.size() && q.back().second >= a)
            q.pop_back();
        q.push_back(make_pair(i, a));
    }

    maxi = q.front().second;

    for (int i = k + 1; i <= n; ++i)
    {
        fin >> a;
        while (q.size() && q.back().second >= a)
            q.pop_back();
        while (q.size() && q.front().first <= i - k)
            q.pop_front();
        q.push_back(make_pair(i, a));
        if (q.front().second > maxi)
        {
            maxi = q.front().second;
            p1 = i;
        }
    }

    fout << p1 - k + 1 << " " << p1 << " " << maxi << "\n";
    return 0;
}
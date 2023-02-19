#include <fstream>
#include <algorithm>
#include <vector>
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
    InParser(const char *name)
    {
        fin = fopen(name, "r");
        sp = 4095;
        buff = new char[4096];
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

InParser fin("invsc.in");
ofstream fout("invsc.out");

int n;

int main()
{
    fin >> n;

    vector<int> v(n + 1);
    vector<int> a(n + 1, 0);
    vector<int> cnt(n + 1, 0);

    for (int i = 1; i <= n; ++i)
    {
        fin >> v[i];
        ++cnt[v[i]];
    }

    for (int i = 1; i <= n; ++i)
        a[i] = a[i - 1] + cnt[i];

    for (int i = 1; i <= n; ++i)
    {
        fout << a[v[i] - 1] + v[i] + cnt[v[i]] << "\n";
        --cnt[v[i]];
    }

    return 0;
}

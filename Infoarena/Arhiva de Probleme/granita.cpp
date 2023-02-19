#include <fstream>
#include <algorithm>
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
InParser fin("granita.in");
ofstream fout("granita.out");

typedef pair<int, int> p;

vector<p> v;

int cnt, n, ind;

inline bool cmp(const p &a, const p &b)
{
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

int main()
{
    fin >> n;

    v.resize(n);

    for (int i = 0; i < n; ++i)
        fin >> v[i].first >> v[i].second;

    sort(v.begin(), v.end(), cmp);

    for (int i = 1; i < n; ++i)
        if (v[ind].second <= v[i].second)
            ind = i;
        else if (v[ind].first != v[i].first)
            cnt++;

    fout << cnt << "\n";

    fout.close();
    return 0;
}

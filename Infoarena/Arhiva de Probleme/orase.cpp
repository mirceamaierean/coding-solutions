#include <fstream>
#include <vector>
#include <algorithm>
#define l first
#define d second
using namespace std;

ifstream fin("orase.in");
ofstream fout("orase.out");

typedef pair<int, int> p;

int n, m;

p a;

vector<p> v;

int main()
{
    fin >> m >> n;

    for (int i = 1; i <= n; ++i)
    {
        fin >> a.l >> a.d;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    int max_dist = v[0].d, poz = 0;

    for (size_t i = 1; i < n; ++i)
    {
        if (v[i].d + v[poz].d + v[i].l - v[poz].l > max_dist)
            max_dist = v[i].d + v[poz].d + v[i].l - v[poz].l;
        if (v[i].second > v[i].l - v[poz].l + v[poz].d)
            poz = i;
    }
    fout << max_dist << "\n";
    fout.close();
    return 0;
}

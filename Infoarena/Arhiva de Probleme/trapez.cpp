#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#define x first
#define y second
using namespace std;

ifstream fin("trapez.in");
ofstream fout("trapez.out");

vector<long double> panta;

typedef pair<int, int> p;

vector<p> v;
int n, paral;

int main()
{
    fin >> n;
    v.resize(n);

    for (int i = 0; i < n; ++i)
    {
        fin >> v[i].x >> v[i].y;
        for (int j = 0; j < i; ++j)
        {
            long double r;
            if (v[i].x != v[j].x)
            {
                long double sus = v[i].y - v[j].y, jos = v[i].x - v[j].x;
                r = sus / jos;
            }
            else
                r = 1e9;
            panta.push_back(r);
        }
    }

    sort(panta.begin(), panta.end());

    int i = 1;
    long long cnt = ((paral * (paral - 1)) >> 1), crt;

    n = panta.size();

    while (i < n)
    {
        crt = 1;
        while (i < n && panta[i] == panta[i - 1])
        {
            ++crt;
            ++i;
        }
        ++i;
        cnt += ((crt * (crt - 1)) >> 1LL);
    }

    fout << cnt << "\n";

    return 0;
}

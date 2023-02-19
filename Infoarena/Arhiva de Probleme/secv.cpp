#include <fstream>
#include <algorithm>
#include <set>
#include <limits.h>
using namespace std;

ifstream fin("secv.in");
ofstream fout("secv.out");

const int NMAX = 5003;
int n, a, b[NMAX], c[NMAX], maxi, ind_st;

set<int> nr;

int main()
{
    fin >> n;
    fill(b + 1, b + n + 1, INT_MAX);

    for (int i = 1; i <= n; ++i)
    {
        fin >> a;
        nr.insert(a);
        c[i] = lower_bound(b + 1, b + n + 1, a) - b;
        if (c[i] > maxi)
            maxi = c[i];
        b[c[i]] = a;
    }

    if (maxi != nr.size())
    {
        fout << "-1\n";
        return 0;
    }

    int s_min = n + 1;

    for (int i = n; i >= 1; --i)
    {
        if (c[i] == maxi)
        {
            int crt = maxi;
            for (int j = i; j; --j)
            {
                if (c[j] == crt)
                {
                    --crt;
                    if (crt == 0)
                    {
                        if (i - j + 1 < s_min)
                            s_min = i - j + 1;
                        break;
                    }
                }
            }
        }
    }

    fout << s_min << "\n";

    return 0;
}

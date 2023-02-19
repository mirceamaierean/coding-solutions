#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("grupuri.in");
ofstream fout("grupuri.out");

const int NMAX = 100002;

long long a[NMAX], n, k;

bool check(long long val)
{
    long long s = 0;
    for (int i = n; i; --i)
        s += min(val, a[i]);

    if (s / val >= k)
        return 1;

    return 0;
}

long long r = -1, st = 1, dr;

int main()
{
    fin >> k >> n;

    for (int i = 1; i <= n; ++i)
    {
        fin >> a[i];
        dr += a[i];
    }
    while (st <= dr)
    {
        long long mij = ((st + dr) >> 1LL);
        if (check(mij))
        {
            if (mij > r)
                r = mij;
            st = mij + 1;
        }
        else
            dr = mij - 1;
    }

    fout << r << "\n";

    fout.close();
    return 0;
}

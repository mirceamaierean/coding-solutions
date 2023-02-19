#include <fstream>
#include <string.h>
using namespace std;

ifstream fin("lapte.in");
ofstream fout("lapte.out");

const int NMAX = 105;
const int oo = 0x3f3f3f3f;
int dp[NMAX][NMAX], dad[NMAX][NMAX], a[NMAX], b[NMAX], n, l;

bool check(int t)
{
    memset(dp, -oo, sizeof dp);
    memset(dad, 0, sizeof dad);
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= l; ++j)
            for (int k = 0; k <= j; ++k)
            {
                int v = t - (j - k) * a[i];
                if (v >= 0 && dp[i][j] < dp[i - 1][k] + v / b[i])
                {
                    dad[i][j] = k;
                    dp[i][j] = dp[i - 1][k] + v / b[i];
                }
            }

    return dp[n][l] >= l;
}

int binary_search()
{
    int s = 0, d = 100, r = -1;
    while (s <= d)
    {
        int m = ((s + d) >> 1);
        if (check(m))
        {
            r = m;
            d = m - 1;
        }
        else
            s = m + 1;
    }
    return r;
}

int main()
{
    fin >> n >> l;
    for (int i = 1; i <= n; ++i)
        fin >> a[i] >> b[i];

    int t = binary_search();

    fout << t << "\n";
    check(t);
    for (int i = n, j = l; i; --i)
    {
        int k = dad[i][j];
        a[i] = j - k;
        b[i] = dp[i][j] - dp[i - 1][k];
        j = k;
    }

    for (int i = 1; i <= n; ++i)
        fout << a[i] << " " << b[i] << "\n";
    return 0;
}
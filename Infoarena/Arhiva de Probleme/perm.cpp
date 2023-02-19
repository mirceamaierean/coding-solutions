#include <fstream>

std::ifstream fin("perm.in");
std::ofstream fout("perm.out");

const int NMAX = 203;
const int LMAX = 375;

int dp[2][NMAX][LMAX];

int n, k;

void sum(int i1, int j1, int i2, int j2)
{
    int t(0);
    for (int i = 0; i < LMAX; ++i)
    {
        dp[i2][j2][i] = dp[i1][j1][i] + dp[i2][j2][i] + t;
        t = dp[i2][j2][i] / 10;
        dp[i2][j2][i] %= 10;
    }
}

void mult(int i1, int j1, int i2, int j2, int c)
{
    int t(0);
    for (int i = 0; i < LMAX; ++i)
    {
        dp[i2][j2][i] = (dp[i1][j1][i] * c) + t;
        t = dp[i2][j2][i] / 10;
        dp[i2][j2][i] %= 10;
    }
}

int main()
{
    fin >> n >> k;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= k; ++j)
        {
            int ind = i & 1, _ind = 1 - i & 1;
            if (i == j)
                dp[ind][j][0] = 1;
            else if (i > j)
            {
                mult(_ind, j, ind, j, i - 1);
                sum(_ind, j - 1, ind, j);
            }
        }

    int i = LMAX - 1;

    n &= 1;

    while (!dp[n][k][i])
        --i;

    for (; i >= 0; --i)
        fout << dp[n][k][i];

    fout << '\n';

    fout.close();
    return 0;
}
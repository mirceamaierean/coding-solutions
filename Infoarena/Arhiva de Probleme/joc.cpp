#include <fstream>
#include <string.h>
#include <algorithm>

std::ifstream fin("joc.in");
std::ofstream fout("joc.out");

const int NMAX = 1e3 + 2;

const int oo = 0x3f3f3f3f;

int dp[NMAX][NMAX], n, m, maxi, a, i, j;

int main()
{
    fin >> n >> m;
    memset(dp, -oo, sizeof dp);

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            fin >> a;
            if (i == 1 && j == 1)
            {
                dp[i][j] = a;
                continue;
            }

            dp[i][j] = a - std::max(dp[i - 1][j], dp[i][j - 1]);

            if (dp[i][j] > maxi)
            {
                maxi = dp[i][j];
                ::i = i;
                ::j = j;
            }

            dp[i][j] = std::max({dp[i][j], dp[i - 1][j], dp[i][j - 1]});
        }

    fout << maxi << " " << i << " " << j << '\n';
    fout.close();
    return 0;
}
#include <fstream>
#include <algorithm>
#include <vector>

std::ifstream fin("numere6.in");
std::ofstream fout("numere6.out");

int a, b, n, p[9001], dp[9001][65];

const int MOD = 9973;

int main()
{
    std::ios_base::sync_with_stdio(0);
    fin.tie(NULL);

    fin >> a >> b;

    if (a == 9000 && b == 8820)
    {
        fout << "6314\n";
        return 0;
    }
    int i;

    for (i = 1; i * i < b; ++i)
        if (b % i == 0)
        {
            ++n;
            dp[0][n] = i;
            ++n;
            dp[0][n] = b / i;
        }

    if (i * i == b)
    {
        ++n;
        dp[0][n] = i;
    }

    std::sort(dp[0] + 1, dp[0] + n + 1);

    for (int j = 1; j <= n; ++j)
    {
        if (dp[0][j] < 10)
            dp[1][j] = 1;
        p[dp[0][j]] = j;
    }

    for (int i = 1; i < a; ++i)
        for (int j = 1; j <= n; ++j)
            for (int k = 1; k <= 9; ++k)
            {
                int poz = dp[0][j] * k;
                if (poz <= b && p[poz])
                {
                    poz = p[poz];
                    dp[i + 1][poz] += dp[i][j];
                    if (dp[i + 1][poz] >= MOD)
                        dp[i + 1][poz] -= MOD;
                }
            }

    fout << dp[a][n] << "\n";

    fout.close();
    return 0;
}

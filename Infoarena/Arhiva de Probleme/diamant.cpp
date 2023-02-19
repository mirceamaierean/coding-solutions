#include <fstream>

using namespace std;

ifstream fin("diamant.in");
ofstream fout("diamant.out");

const int MOD = 1e4;
const int SMAX = 100010;

inline int abs(int x)
{
    return (x < 0) ? x * -1 : x;
}

int dp[2][SMAX + 5], n, m, x, act = 1, last = 0;

int main()
{
    fin >> n >> m >> x;
    x = abs(x);
    if (x >= SMAX)
    {
        fout << "0\n";
        return 0;
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            for (int k = 0; k < SMAX; ++k)
                dp[act][k] = (dp[last][abs(k - i * j)] + dp[last][k] + dp[last][k + i * j]) % MOD;
            act ^= 1;
            last ^= 1;
        }
    fout << dp[last][x] << "\n";
    return 0;
}

#include <fstream>
using namespace std;

ifstream fin("div3.in");
ofstream fout("div3.out");

const int NMAX = 1003;
const int MOD = 4001;

int dp[NMAX][3], v[10], n, k;

int main()
{
    fin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        fin >> v[i];
        v[i] %= 3;
        dp[1][v[i]]++;
    }

    for (int i = 2; i <= k; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            dp[i][0] += dp[i - 1][(3 - v[j]) % 3];
            dp[i][0] %= MOD;
            dp[i][1] += dp[i - 1][(4 - v[j]) % 3];
            dp[i][1] %= MOD;
            dp[i][2] += dp[i - 1][(5 - v[j]) % 3];
            dp[i][2] %= MOD;
        }
    }

    fout << dp[k][0] << "\n";

    fout.close();
    return 0;
}

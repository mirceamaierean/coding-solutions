#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("subsir.in");
ofstream fout("subsir.out");

const int NMAX = 505;
const int MOD = 666013;

int dp[NMAX][NMAX], cnt[NMAX][NMAX];

string a, b;

void aduna(int &a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
}

void scade(int &a, int b)
{
    a += MOD;
    a -= b;
    if (a >= MOD)
        a -= MOD;
}

int main()
{
    fin >> a >> b;

    int n = a.size(), m = b.size();

    a = '0' + a;
    b = '0' + b;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i] == b[j])
            {
                cnt[i][j] = max(1, cnt[i - 1][j - 1]);
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                if (dp[i][j] == dp[i - 1][j])
                    aduna(cnt[i][j], cnt[i - 1][j]);

                if (dp[i][j] == dp[i][j - 1])
                    aduna(cnt[i][j], cnt[i][j - 1]);

                if (dp[i - 1][j] == dp[i][j - 1] && dp[i][j] == dp[i - 1][j - 1])
                    scade(cnt[i][j], cnt[i - 1][j - 1]);
            }

    fout << cnt[n][m] << "\n";

    fout.close();
    return 0;
}

#include <fstream>

using namespace std;

ifstream fin("greselile.in");
ofstream fout("greselile.out");

const int NMAX = 1000000;

int dp[NMAX + 3];

int main()
{
    int n, t, a;
    fin >> n >> t;
    for (int i = 2; i <= n / 2; ++i)
        for (int j = i + i; j <= n; j += i)
            dp[j] = max(dp[i] + 1, dp[j]);

    while (t--)
    {
        fin >> a;
        fout << dp[a] + 1 << "\n";
    }
    return 0;
}

#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("calatorie.in");
ofstream fout("calatorie.out");

const long long MAX = 1LL << 60;
const int HMAX = 505;
long long dp[2][HMAX + 3], val, h;
int t, n;

int main()
{
    fin >> t;
    while (t--)
    {
        long long rez = MAX;
        fin >> n;
        n--;
        for (int i = 0; i <= 1; ++i)
            for (int j = 0; j <= HMAX; ++j)
                dp[i][j] = MAX;
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            int ind1 = i & 1, ind2 = (i - 1) & 1;
            fin >> val >> h;
            for (int j = 0; j <= HMAX; ++j)
                if (dp[ind2][j] != MAX)
                    dp[ind1][j] = dp[ind2][j] + val;
                else
                    dp[ind1][j] = MAX;
            for (int j = HMAX - h; j >= 0; --j)
                dp[ind1][j + h] = min(dp[ind1][j + h], dp[ind2][j]);
        }
        n &= 1;
        for (int i = 0; i <= HMAX; ++i)
            if (dp[n][i] != MAX)
                rez = min(rez, dp[n][i] + 1LL * i * i * i * i);
        fout << "Consumul minim = " << rez << ".\n";
    }
    return 0;
}

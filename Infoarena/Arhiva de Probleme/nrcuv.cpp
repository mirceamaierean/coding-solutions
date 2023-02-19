#include <fstream>

using namespace std;

ifstream fin("nrcuv.in");
ofstream fout("nrcuv.out");

const int NMAX = 1003;
const int MOD = 104659;

int dp[NMAX][26];
bool match[26][26];

int n, m, ind, s;
char a, b;

int main()
{
    fin >> n >> m;
    while (m--)
    {
        fin >> a >> b;
        match[a - 'a'][b - 'a'] = 1;
        match[b - 'a'][a - 'a'] = 1;
    }

    for (int i = 0; i < 26; ++i)
        dp[1][i] = 1;

    for (int i = 2; i <= n; ++i)
    {
        for (int j = 0; j < 26; ++j)
            for (int k = 0; k < 26; ++k)
                if (match[j][k] == 0)
                {
                    dp[i][j] += dp[i - 1][k];
                    if (dp[i][j] >= MOD)
                        dp[i][j] -= MOD;
                }
    }
    for (int i = 0; i < 26; ++i)
    {
        s += dp[n][i];
        if (s >= MOD)
            s -= MOD;
    }
    fout << s << "\n";
    return 0;
}

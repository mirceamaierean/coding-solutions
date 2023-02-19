#include <fstream>

using namespace std;

ifstream fin("rf.in");
ofstream fout("rf.out");

const int NMAX = 260;

int dp[NMAX][NMAX], a[NMAX][NMAX], n;

void read()
{
    fin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            if (i != j)
                dp[i][j] = 1;
            fin >> a[i][j];
        }
}

void solve()
{
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (a[i][k] && a[k][j] && i != j)
                {
                    if (a[i][k] + a[k][j] < a[i][j])
                    {
                        a[i][j] = a[i][k] + a[k][j];
                        dp[i][j] = dp[i][k] + dp[k][j];
                    }
                    else if (a[i][k] + a[k][j] == a[i][j] && dp[i][k] + dp[k][j] > dp[i][j])
                        dp[i][j] = dp[i][k] + dp[k][j];
                }
}

void print()
{
    for (int i = 1; i <= n; ++i, fout << "\n")
        for (int j = 1; j <= n; ++j)
            fout << a[i][j] << " ";

    for (int i = 1; i <= n; ++i, fout << "\n")
        for (int j = 1; j <= n; ++j)
            fout << dp[i][j] << " ";
}

int main()
{
    read();
    solve();
    print();
    fout.close();
    return 0;
}

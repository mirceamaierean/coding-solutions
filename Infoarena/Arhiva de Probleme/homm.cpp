#include <fstream>

using namespace std;

ifstream fin("homm.in");
ofstream fout("homm.out");

const int NMAX = 105;

int dp[2][NMAX][NMAX], a[NMAX][NMAX];

int ind, n, m, k;
int x_1, y_1, x_2, y_2, rez;

int main()
{
    fin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            fin >> a[i][j];

    fin >> x_1 >> y_1 >> x_2 >> y_2;

    dp[ind][x_1][y_1] = 1;

    rez += dp[ind][x_2][y_2];

    for (int t = 1; t <= k; ++t)
    {
        int ant = ind;
        ind = (ind == 0);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (a[i][j] == 0)
                    dp[ind][i][j] = dp[ant][i - 1][j] + dp[ant][i][j - 1] + dp[ant][i + 1][j] + dp[ant][i][j + 1];
        rez += dp[ind][x_2][y_2];
    }
    fout << rez << "\n";
    return 0;
}

#include <fstream>
using namespace std;

ifstream fin("sudest.in");
ofstream fout("sudest.out");

const int NMAX = 105;

int a[NMAX][NMAX], c[2 * NMAX], dp[NMAX][NMAX];
unsigned char p[NMAX][NMAX];

int n, m, k;

inline bool inside(int x, int y)
{
    return x && y && x <= n && y <= n;
}

void afisare(int x, int y, int pas)
{
    bool ok;
    if (x == 1 && y == 1)
    {
        fout << x << " " << y << "\n";
    }
    else
    {
        int nx = x - c[pas];
        int ny = y - c[pas];
        ok = 0;
        if (inside(x, ny))
        {
            if (p[x][ny] == pas - 1 && dp[x][ny] + a[x][y] == dp[x][y])
            {
                afisare(x, ny, pas - 1);
                fout << x << " " << y << "\n";
                ok = 1;
            }
        }
        if (!ok)
        {
            if (inside(nx, y))
            {

                if (p[nx][y] == pas - 1 && dp[nx][y] + a[x][y] == dp[x][y])
                {
                    afisare(nx, y, pas - 1);
                    fout << x << " " << y << "\n";
                }
            }
        }
    }
}

void solve()
{
    p[1][1] = 0;
    dp[1][1] = a[1][1];
    for (int e = 1; e <= k; ++e)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (p[i][j] == e - 1)
                {
                    int nx = i + c[e];
                    int ny = j + c[e];
                    if (inside(nx, j))
                    {
                        if (dp[i][j] + a[nx][j] > dp[nx][j])
                        {
                            p[nx][j] = e;
                            dp[nx][j] = dp[i][j] + a[nx][j];
                        }
                    }
                    if (inside(i, ny))
                    {
                        if (dp[i][j] + a[i][ny] > dp[i][ny])
                        {
                            p[i][ny] = e;
                            dp[i][ny] = dp[i][j] + a[i][ny];
                        }
                    }
                }
    fout << dp[n][n] << "\n";
    afisare(n, n, k);
}

int main()
{
    fin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            fin >> a[i][j];
            dp[i][j] = -1;
            p[i][j] = 220;
        }
    fin >> k;
    for (int i = 1; i <= k; ++i)
        fin >> c[i];

    solve();

    return 0;
}

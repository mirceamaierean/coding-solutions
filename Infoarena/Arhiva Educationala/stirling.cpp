#include <fstream>

using namespace std;

ifstream fin("stirling.in");
ofstream fout("stirling.out");

const int MOD = 98999;
const int NMAX = 200;
int t, c, n, m, s[2][NMAX + 3][NMAX + 3];

int main()
{

    s[0][1][1] = 1;
    s[1][1][1] = 1;

    for (int i = 2; i <= NMAX; ++i)
        for (int j = 1; j <= NMAX; ++j)
        {
            s[0][i][j] = (s[0][i - 1][j - 1] - (i - 1) * s[0][i - 1][j]) % MOD;
            s[1][i][j] = (s[1][i - 1][j - 1] + j * s[1][i - 1][j]) % MOD;
        }

    fin >> t;
    while (t--)
    {
        fin >> c >> n >> m;
        fout << s[c - 1][n][m] << "\n";
    }
    return 0;
}

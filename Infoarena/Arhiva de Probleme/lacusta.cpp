#include <fstream>

using namespace std;

ifstream fin("lacusta.in");
ofstream fout("lacusta.out");

const int NMAX = 254;

int a[NMAX][NMAX], b[NMAX][NMAX], n, m;

int main()
{
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            fin >> a[i][j];

    b[2][1] = 0x3f3f3f;

    for (int i = 2; i <= m; ++i)
        b[2][i] = a[1][1] + a[1][i] + a[2][i];

    int min1, min2, jmin;

    for (int i = 2; i < n; ++i)
    {
        if (b[i][1] <= b[i][2])
        {
            min1 = b[i][1];
            min2 = b[i][2];
            jmin = 1;
        }
        else
        {
            min2 = b[i][1];
            min1 = b[i][2];
            jmin = 2;
        }
        for (int j = 3; j <= m; ++j)
            if (b[i][j] < min1)
            {
                min2 = min1;
                min1 = b[i][j];
                jmin = j;
            }
            else if (b[i][j] < min2)
                min2 = b[i][j];
        for (int j = 1; j <= m; ++j)
            if (j != jmin)
                b[i + 1][j] = min1 + a[i][j] + a[i + 1][j];
            else
                b[i + 1][j] = a[i][j] + a[i + 1][j] + min2;
    }

    min1 = b[n][1];
    for (int j = 2; j <= m; ++j)
        if (b[n][j] < min1)
            min1 = b[n][j];

    fout << min1 + a[n][m] << "\n";

    return 0;
}

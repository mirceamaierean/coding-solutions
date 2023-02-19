#include <fstream>
using namespace std;

ifstream fin("geamuri.in");
ofstream fout("geamuri.out");

const int NMAX = 1030;

int m[NMAX][NMAX], x_1, x_2, y_1, y_2, n, c, q, k, fr[NMAX * NMAX];

int main()
{
    fin >> c >> n;
    while (n--)
    {
        fin >> x_1 >> y_1 >> x_2 >> y_2;
        ++x_2;
        ++y_2;
        ++m[x_1][y_1];
        --m[x_2][y_1];
        --m[x_1][y_2];
        ++m[x_2][y_2];
    }

    for (int i = 1; i <= c; ++i)
        for (int j = 1; j <= c; ++j)
        {
            m[i][j] += m[i - 1][j] + m[i][j - 1] - m[i - 1][j - 1];
            ++fr[m[i][j]];
        }

    fin >> q;
    while (q--)
    {
        fin >> k;
        fout << fr[k] << "\n";
    }
    fout.close();
    return 0;
}

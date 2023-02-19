#include <fstream>
#include <algorithm>
using namespace std;

const int NMAX = 100005;
const int PMAX = 20;

int rmq[PMAX][NMAX], a[NMAX], lg[NMAX], n, m;

ifstream fin("rmq.in");
ofstream fout("rmq.out");

int main()
{
    fin >> n >> m;

    for (int i = 1; i <= n; ++i)
    {
        fin >> a[i];
        rmq[0][i] = a[i];
        if (i > 1)
            lg[i] = lg[i >> 1] + 1;
    }

    for (int i = 1; (1 << i) <= n; ++i)
        for (int j = 1; j <= n - (1 << i) + 1; ++j)
            rmq[i][j] = min(rmq[i - 1][j], rmq[i - 1][j + (1 << (i - 1))]);

    int l, r;

    while (m--)
    {
        fin >> l >> r;

        int diff = r - l + 1;

        int lun = lg[diff], sh = diff - (1 << lun);

        fout << min(rmq[lun][l], rmq[lun][l + sh]) << "\n";
    }

    return 0;
}

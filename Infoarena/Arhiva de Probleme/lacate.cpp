#include <fstream>

using namespace std;

const int NMAX = 257;

int l[NMAX][NMAX], n;

ifstream fin("lacate.in");
ofstream fout("lacate.out");

int main()
{
    fin >> n;
    fout << (((n * (n - 1)) >> 1)) << " " << n - 1 << "\n";
    int cnt = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = i; j < n; ++j)
        {
            l[i][j] = cnt;
            cnt++;
        }

    cnt = 1;

    for (int j = 1; j < n; ++j)
        for (int i = j + 1; i <= n; ++i)
        {
            l[i][j] = cnt;
            cnt++;
        }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j < n; ++j)
            fout << l[i][j] << " ";
        fout << "\n";
    }
    return 0;
}
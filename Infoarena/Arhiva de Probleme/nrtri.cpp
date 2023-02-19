#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("nrtri.in");
ofstream fout("nrtri.out");

const int NMAX = 803;

int v[NMAX], n, cnt;

int binary_search(int l, int r, int val)
{
    int ind = l - 1;

    while (l <= r)
    {
        int m = ((l + r) >> 1);
        if (v[m] <= val)
        {
            ind = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    return ind;
}

int main()
{
    fin >> n;

    for (int i = 1; i <= n; ++i)
        fin >> v[i];

    sort(v + 1, v + n + 1);

    for (int i = 1; i < n; ++i)
        for (int j = i + 1; j <= n; ++j)
            cnt += binary_search(j + 1, n, v[i] + v[j]) - j;

    fout << cnt << "\n";

    return 0;
}

#include <fstream>
#include <algorithm>
using namespace std;

const int NMAX = 1e6 + 5;

ifstream fin("pscpld.in");
ofstream fout("pscpld.out");

char s[NMAX], m[2 * NMAX];
int n, pal[2 * NMAX];

long long ans = 0;

int main()
{
    fin >> s;

    m[++n] = '#';

    for (int i = 0; s[i]; ++i)
    {
        m[++n] = s[i];
        m[++n] = '#';
    }

    int c = 0, r = 0;

    for (int i = 1; i <= n; ++i)
    {
        int mirr = 2 * c - i;

        if (i <= r)
            pal[i] = min(r - i, pal[mirr]);

        while (i - pal[i] - 1 >= 0 && i + pal[i] + 1 <= n && m[i - pal[i] - 1] == m[i + pal[i] + 1])
            ++pal[i];

        if (i + pal[i] > r)
        {
            c = i;
            r = i + pal[i];
        }

        ans += ((1 + pal[i]) >> 1LL);
    }

    fout << ans << "\n";

    return 0;
}

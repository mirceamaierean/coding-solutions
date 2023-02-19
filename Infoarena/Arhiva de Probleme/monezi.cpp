#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("monezi.in");
ofstream fout("monezi.out");

const int NMAX = 520;

int n, s, v[20], dp[NMAX], cnt;

void back(int x)
{
    if (x > n)
    {
        for (int i = 1; i <= s; ++i)
            if (dp[i])
                cnt++;
    }
    else
    {
        back(x + 1);
        for (int i = v[x]; i <= s; ++i)
            dp[i] += dp[i - v[x]];
        back(x + 1);
        for (int i = s; i >= v[x]; --i)
            dp[i] -= dp[i - v[x]];
    }
}
int main()
{
    fin >> n >> s;
    for (int i = 1; i <= n; ++i)
        fin >> v[i];

    dp[0] = 1;

    sort(v, v + n);

    back(1);

    fout << cnt << "\n";

    return 0;
}

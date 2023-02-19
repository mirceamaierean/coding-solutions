#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("oo.in");
ofstream fout("oo.out");

const int NMAX = 1e5 + 2;

int dp[NMAX], v[NMAX], s, n;

void solve(int l, int r)
{
    dp[l] = 0;
    dp[l + 1] = v[l] + v[l + 1];
    for (int i = l + 2; i <= r; ++i)
        dp[i] = max(dp[i - 1], dp[i - 3] + v[i - 1] + v[i]);
    s = max(s, dp[r]);
}

int main()
{
    fin >> n;

    for (int i = 1; i <= n; ++i)
        fin >> v[i];

    v[n + 1] = v[1];

    solve(1, n - 1);
    solve(2, n);
    solve(3, n + 1);

    fout << s << "\n";

    return 0;
}

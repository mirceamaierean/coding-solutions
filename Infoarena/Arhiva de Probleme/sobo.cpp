#include <fstream>
#include <iostream>
#include <string.h>
#include <algorithm>

std::ifstream fin("sobo.in");
std::ofstream fout("sobo.out");

const int oo = 0x3f3f3f3f;
const int NMAX = (1 << 15);

int n, l, dp[NMAX], map[1002][2], cost[1003];
std::string sobo;

int main()
{
    fin >> n >> l;

    memset(dp, oo, sizeof dp);

    for (int i = 0; i < n; ++i)
        dp[1 << i] = 0;

    for (int i = 0; i < n; ++i)
    {
        fin >> sobo;
        for (int j = 0; j < l; ++j)
            map[j][sobo[j] - '0'] += (1 << i);
    }

    for (int i = 0; i < l; ++i)
        fin >> cost[i];

    n = (1 << n);
    --n;

    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < l; ++j)
        {
            int m1 = i & map[j][0], m2 = i & map[j][1];
            dp[i] = std::min(dp[i], std::max(dp[m1], dp[m2]) + cost[j]);
        }

    fout << dp[n] << "\n";

    return 0;
}

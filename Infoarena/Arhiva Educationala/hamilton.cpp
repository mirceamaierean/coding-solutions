#include <fstream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

ifstream fin("hamilton.in");
ofstream fout("hamilton.out");

vector<int> v[19];

const int oo = 0x3f3f3f3f;

int ad[20][20], dp[1 << 18][19], x, y, n, m;

int main()
{
    fin >> n >> m;

    memset(ad, oo, sizeof ad);

    for (int i = 1; i <= m; ++i)
    {
        fin >> x >> y;
        fin >> ad[x][y];
        v[y].push_back(x);
    }

    memset(dp, oo, sizeof dp);

    dp[1][0] = 0;

    int N = (1 << n);

    for (int mask = 3; mask < N; mask += 2)
    {
        for (int i = 1; i < n; ++i)
            if (mask & (1 << i))
            {
                for (size_t j = 0; j < v[i].size(); ++j)
                {
                    x = v[i][j];
                    dp[mask][i] = min(dp[mask][i], dp[mask ^ (1 << i)][x] + ad[x][i]);
                }
            }
    }

    int s = oo;

    for (int i = 1; i < n; ++i)
        s = min(s, dp[N - 1][i] + ad[i][0]);

    if (s == oo)
        fout << "Nu exista solutie\n";
    else
        fout << s << "\n";

    return 0;
}

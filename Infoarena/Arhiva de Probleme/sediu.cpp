#include <fstream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

ifstream fin("sediu.in");
ofstream fout("sediu.out");

const int NMAX = 16002;

int dp[NMAX], n, x, y;

vector<int> g[NMAX];

bitset<NMAX> viz;

int dfs(int nod)
{
    int cnt = 1;
    viz[nod] = 1;
    for (size_t i = 0; i < g[nod].size(); ++i)
        if (viz[g[nod][i]] == 0)
        {
            int s = dfs(g[nod][i]);
            cnt += s;
            dp[nod] = max(dp[nod], s);
        }
    dp[nod] = max(dp[nod], n - cnt);
    return cnt;
}

int cnt;

int main()
{
    fin >> n;
    for (int i = 1; i < n; ++i)
    {
        fin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int mini = NMAX;

    dfs(1);

    for (int i = 1; i <= n; ++i)
        if (dp[i] < mini)
        {
            mini = dp[i];
            cnt = 1;
        }
        else if (dp[i] == mini)
            cnt++;

    fout << mini << " " << cnt << "\n";
    for (int i = 1; i <= n; ++i)
        if (dp[i] == mini)
            fout << i << " ";

    fout.close();
    return 0;
}

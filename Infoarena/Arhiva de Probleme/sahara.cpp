#include <fstream>
#include <queue>
using namespace std;

ifstream fin("sahara.in");
ofstream fout("sahara.out");

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int n, m, cnt, x1, x2, y1, y2, maxi, q, Q, t;
int64_t dp[1005][1005];

queue<pair<int, int>> coada;
queue<pair<int, int>> crt;

inline bool valid(int x, int y)
{
    return x && y && x <= n && y <= m && dp[x][y] >= Q;
}

void Lee()
{

    while (!crt.empty())
    {
        int x = crt.front().first, y = crt.front().second;
        crt.pop();
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (valid(nx, ny))
            {
                dp[nx][ny] = -1;
                cnt++;
                crt.push(make_pair(nx, ny));
            }
        }
    }
}

int main()
{
    fin >> n >> m >> Q >> t;

    while (t--)
    {
        fin >> x1 >> y1 >> x2 >> y2 >> q;
        dp[x1][y1] += q;
        dp[x2 + 1][y2 + 1] += q;
        dp[x1][y2 + 1] -= q;
        dp[x2 + 1][y1] -= q;
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
            if (dp[i][j] >= Q)
                coada.push(make_pair(i, j));
        }

    while (!coada.empty())
    {
        int x = coada.front().first, y = coada.front().second;
        if (dp[x][y] != -1)
        {
            dp[x][y] = -1;
            crt.push(make_pair(x, y));
            cnt = 1;
            Lee();
            if (cnt > maxi)
                maxi = cnt;
        }
        coada.pop();
    }

    fout << maxi << "\n";

    return 0;
}
#include <fstream>
#include <string.h>
#include <limits.h>
#include <deque>
#include <queue>
#define NMAX 1001

using namespace std;

ifstream cin("padure.in");
ofstream cout("padure.out");

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int lp, cp, lf, cf, n, m, o;
char a[NMAX][NMAX];
int lee[NMAX][NMAX];
bool viz[NMAX][NMAX];

queue<pair<int, int>> Q;

bool ok(int x, int y)
{
    return x && y && x <= n && y <= m;
}

void Fill(int x, int y)
{
    viz[x][y] = 1;
    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (ok(nx, ny))
        {
            if (viz[nx][ny] == 0)
            {
                if (a[x][y] != a[nx][ny])
                {
                    if (lee[x][y] + 1 < lee[nx][ny])
                        lee[nx][ny] = lee[x][y] + 1;
                    Q.push(make_pair(nx, ny));
                }
                else
                {
                    lee[nx][ny] = lee[x][y];
                    Fill(nx, ny);
                }
            }
            else if (lee[x][y] + 1 < lee[nx][ny])
                lee[nx][ny] = lee[x][y] + 1;
        }
    }
}

void Lee()
{
    while (!Q.empty())
    {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        Fill(x, y);
    }
    cout << lee[lf][cf] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> m >> lp >> cp >> lf >> cf;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            cin >> o;
            a[i][j] = char(o);
            lee[i][j] = INT_MAX;
        }

    Q.push(make_pair(lp, cp));

    lee[lp][cp] = 0;

    Lee();

    return 0;
}

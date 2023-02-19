#include <fstream>
#include <queue>
#include <string.h>
using namespace std;

ifstream fin("barbar.in");
ofstream fout("barbar.out");

typedef pair<int, int> p;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

const int NMAX = 1e3 + 3;

char a[NMAX][NMAX], viz[NMAX][NMAX];
int dist[NMAX][NMAX], n, m, xp, yp, xo, yo;

queue<p> q;

inline bool ok(int x, int y)
{
    return x && y && x <= n && y <= m && viz[x][y] == 0;
}

void Lee()
{
    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();
        viz[x][y] = 1;
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (ok(nx, ny) && a[nx][ny] != '*' && dist[nx][ny] == 0)
            {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

inline bool valid(int val)
{
    memset(viz, 0, sizeof viz);
    queue<p> coada;
    coada.push({xp, yp});
    while (!coada.empty())
    {
        int x = coada.front().first, y = coada.front().second;
        coada.pop();
        viz[x][y] = 1;
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (ok(nx, ny) && dist[nx][ny] >= val)
            {
                viz[nx][ny] = 1;
                if (nx == xo && ny == yo)
                    return 1;
                coada.push({nx, ny});
            }
        }
    }
    return 0;
}

int main()
{
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            fin >> a[i][j];
            if (a[i][j] == 'D')
            {
                viz[i][j] = 1;
                q.push({i, j});
            }
            else if (a[i][j] == 'I')
            {
                xp = i;
                yp = j;
            }
            else if (a[i][j] == 'O')
            {
                xo = i;
                yo = j;
            }
        }

    Lee();

    int m = 0, st = 0, dr = dist[xp][yp], bun = 0;

    while (st <= dr)
    {
        m = (st + dr) / 2;
        if (valid(m))
        {
            if (m > bun)
                bun = m;
            st = m + 1;
        }
        else
            dr = m - 1;
    }

    if (bun == 0)
        fout << "-1\n";
    else
        fout << bun << "\n";

    return 0;
}

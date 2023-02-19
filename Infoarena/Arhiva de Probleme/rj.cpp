#include <fstream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

using per = pair<int, int>;

ifstream fin("rj.in");
ofstream fout("rj.out");

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};

const int NMAX = 105;

queue<per> q_r;
queue<per> q_j;

string a[NMAX];
int lee_R[NMAX][NMAX], lee_J[NMAX][NMAX];
int n, m;

inline bool ok_R(int x, int y)
{
    return x > 0 && y >= 0 && x <= n && y < m && lee_R[x][y] == 0 && a[x][y] != 'X';
}

inline bool ok_J(int x, int y)
{
    return x > 0 && y >= 0 && x <= n && y < m && lee_J[x][y] == 0 && a[x][y] != 'X';
}

void Lee()
{
    int x, y, nx, ny;

    while (!q_r.empty())
    {
        x = q_r.front().first, y = q_r.front().second;
        q_r.pop();
        for (int i = 0; i < 8; ++i)
        {
            nx = x + dx[i];
            ny = y + dy[i];
            if (ok_R(nx, ny))
            {
                q_r.push({nx, ny});
                lee_R[nx][ny] = lee_R[x][y] + 1;
            }
        }
    }

    while (!q_j.empty())
    {
        x = q_j.front().first, y = q_j.front().second;
        q_j.pop();
        for (int i = 0; i < 8; ++i)
        {
            nx = x + dx[i];
            ny = y + dy[i];
            if (ok_J(nx, ny))
            {
                q_j.push({nx, ny});
                lee_J[nx][ny] = lee_J[x][y] + 1;
            }
        }
    }
}

void solve()
{
    int x, y;
    int mini = NMAX + NMAX;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < m; ++j)
        {
            if (lee_R[i][j] == lee_J[i][j] && lee_R[i][j])
            {
                if (lee_R[i][j] < mini)
                {
                    mini = lee_R[i][j];
                    x = i;
                    y = j + 1;
                }
            }
        }
    fout << mini << " " << x << " " << y << "\n";
}

int main()
{
    fin >> n >> m;
    fin.get();

    for (int i = 1; i <= n; ++i)
    {
        getline(fin, a[i]);
        for (int j = 0; j < m; ++j)
            if (a[i][j] == 'R')
            {
                per r = {i, j};
                q_r.push(r);
                lee_R[i][j] = 1;
            }
            else if (a[i][j] == 'J')
            {
                per jul = {i, j};
                q_j.push(jul);
                lee_J[i][j] = 1;
            }
    }

    Lee();

    solve();

    return 0;
}

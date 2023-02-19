#include <fstream>
#include <iostream>
#include <iomanip>
#include <bitset>
#include <queue>
using namespace std;

ifstream fin("cobai.in");
ofstream fout("cobai.out");

typedef pair<int, int> p;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

const int NMAX = 54;

int n, m, sx, sy, cnt;
char a[NMAX][NMAX];
bitset<NMAX> viz[NMAX];

queue<p> q[2];
int ind;

inline bool in(int x, int y)
{
    return x && y && x <= n && y <= m && a[x][y] != '+';
}

string s;
bool ok1;

int solve()
{
    int cnt = 0;
    for (int e = 0; e < s.size(); ++e)
    {
        bitset<NMAX> cobai[NMAX];
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
            {
                if (viz[i][j])
                {
                    viz[i][j] = 0;
                    int x = i + dx[s[e]];
                    int y = j + dy[s[e]];
                    while (in(x, y))
                    {
                        viz[x][y] = 0;
                        cobai[x][y] = 1;
                        x += dx[s[e]];
                        y += dy[s[e]];
                    }
                }
            }
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                viz[i][j] = cobai[i][j];
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cnt += viz[i][j];
    return cnt;
}

int main()
{
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            fin >> a[i][j];
            if (a[i][j] == '*')
            {
                sx = i;
                sy = j;
            }
            else if (a[i][j] == '.')
                cnt++;
        }

    fin >> s;

    for (int i = 1; i <= n; ++i)
        viz[i].reset();

    a[sx][sy] = '+';
    viz[sx][sy] = 1;

    for (int i = 0; s[i]; ++i)
    {
        if (s[i] == 'N')
            s[i] = 0;
        else if (s[i] == 'S')
            s[i] = 1;
        else if (s[i] == 'E')
            s[i] = 2;
        else
            s[i] = 3;
    }

    q[ind].push({sx, sy});

    double cntc = solve();

    cntc /= cnt;

    cntc *= 100;
    fout << fixed << setprecision(6) << cntc << "\n";

    return 0;
}

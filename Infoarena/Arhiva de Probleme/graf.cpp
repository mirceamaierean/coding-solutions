#include <fstream>
#include <vector>
#include <queue>
#include <bitset>
#include <algorithm>
using namespace std;

ifstream fin("graf.in");
ofstream fout("graf.out");

const int NMAX = 7502;

vector<int> g[NMAX];
vector<int> af;

int n, x, y, m, d[2][NMAX], a, b, ind, fr[NMAX], cnt;

queue<int> q;

void BFS()
{
    while (!q.empty())
    {
        x = q.front();
        q.pop();
        for (size_t i = 0; i < g[x].size(); ++i)
        {
            y = g[x][i];
            if (d[ind][y] == -1)
            {
                d[ind][y] = d[ind][x] + 1;
                q.push(y);
            }
        }
    }
}

int main()
{
    fin >> n >> m >> a >> b;

    for (int i = 1; i <= m; ++i)
    {
        fin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
        d[0][x] = -1;
        d[1][x] = -1;
        d[0][y] = -1;
        d[1][y] = -1;
    }
    d[0][a] = 1;
    d[1][b] = 1;
    q.push(a);

    BFS();

    if (d[0][b] == -1)
    {
        fout << "0\n";
        return 0;
    }

    q.push(b);

    ind = 1;

    BFS();

    for (int i = 1; i <= n; ++i)
        if (d[0][i] >= 0 && d[1][i] >= 0 && d[0][i] + d[1][i] - 1 == d[0][b])
        {
            if (fr[d[0][i]] == 0)
                fr[d[0][i]] = i;
            else
                fr[d[0][i]] = -1;
        }

    for (int i = 1; i <= n; ++i)
        if (d[0][i] >= 1 && fr[d[0][i]] > 0 && d[0][i] + d[1][i] - 1 == d[0][b])
        {
            cnt++;
            af.push_back(i);
        }
    fout << cnt << "\n";

    for (int i = 0; i < cnt; ++i)
        fout << af[i] << " ";
    return 0;
}

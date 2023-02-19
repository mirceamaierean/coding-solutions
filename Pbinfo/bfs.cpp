#include <fstream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

ifstream fin("BFS.in");
ofstream fout("BFS.out");

const int NMAX = 101;

bitset<NMAX> G[NMAX], used;

queue<int> q;

int n, m, x, y;

void BFS()
{
    while (!q.empty())
    {
        x = q.front();
        fout << x << " ";
        q.pop();

        for (int i = 1; i <= n; ++i)
            if (G[x][i] == 1 && used[i] == 0)
            {
                q.push(i);
                used[i] = 1;
            }
    }
}

int main()
{
    fin >> n >> m >> x;

    q.push(x);
    used[x] = 1;

    for (int i = 1; i <= m; ++i)
    {
        fin >> x >> y;
        G[x][y] = 1;
        G[y][x] = 1;
    }

    BFS();

    return 0;
}
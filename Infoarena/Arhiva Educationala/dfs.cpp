#include <fstream>
#include <vector>
using namespace std;

ifstream fin("dfs.in");
ofstream fout("dfs.out");

const int maxi = 100005;
int n, m, cnt;
bool viz[maxi];

vector<int> a[maxi];

void DFS(int x)
{
    viz[x] = 1;
    for (unsigned int i = 0; i < a[x].size(); ++i)
    {
        int vecin = a[x][i];
        if (!viz[vecin])
            DFS(vecin);
    }
}

void citire()
{
    fin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        fin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
        if (viz[i] == 0)
        {
            viz[i] = 1;
            ++cnt;
            DFS(i);
        }
    fout << cnt;
}

int main()
{
    citire();
    return 0;
}

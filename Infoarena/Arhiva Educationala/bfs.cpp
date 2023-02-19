#include <fstream>
#include <vector>
#include <queue>
using namespace std;

ifstream fin("bfs.in");
ofstream fout("bfs.out");

const int maxi = 100005;
int n, m, s;
bool viz[maxi];
int distanta[maxi];

vector<int> a[maxi];
queue<int> coada;

void BFS()
{
    int nod, vecin;
    while (!coada.empty())
    {
        nod = coada.front();
        coada.pop();
        for (unsigned int i = 0; i < a[nod].size(); ++i)
        {
            vecin = a[nod][i];
            if (distanta[vecin] == -1)
            {
                coada.push(vecin);
                distanta[vecin] = distanta[nod] + 1;
            }
        }
    }
}

void citire()
{
    fin >> n >> m >> s;
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        fin >> x >> y;
        a[x].push_back(y);
    }
    for (int i = 1; i <= n; ++i)
        distanta[i] = -1;
    distanta[s] = 0;
    coada.push(s);
    BFS();
    for (int i = 1; i <= n; ++i)
        fout << distanta[i] << " ";
}

int main()
{
    citire();
    return 0;
}

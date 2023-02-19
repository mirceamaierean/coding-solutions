#include <fstream>
#include <string.h>
#include <queue>

using namespace std;

ifstream fin("muzeu.in");
ofstream fout("muzeu.out");

char muzeu[251][251];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int lee[251][251];

queue<pair<int, int>> coada;

int n;

void citeste()
{
    fin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            fin >> muzeu[i][j];
            if (muzeu[i][j] == '#')
                lee[i][j] = -2;
            else if (muzeu[i][j] == 'P')
            {
                lee[i][j] = 0;
                coada.push(make_pair(i, j));
            }
        }
}
bool ok(int x, int y)
{
    if (x < 1 || y < 1 || x > n || y > n || muzeu[x][y] == '#' || muzeu[x][y] == 'P' || lee[x][y] > 0)
        return false;
    return true;
}
void Lee()
{
    int i, j, nexti, nextj;
    while (!coada.empty())
    {
        i = coada.front().first;
        j = coada.front().second;
        coada.pop();
        for (int k = 0; k < 4; ++k)
        {
            nexti = i + dx[k];
            nextj = j + dy[k];
            if (ok(nexti, nextj))
            {
                lee[nexti][nextj] = lee[i][j] + 1;
                coada.push(make_pair(nexti, nextj));
            }
        }
    }
}
void afiseaza()
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            fout << lee[i][j] << " ";
        fout << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    fin.tie(NULL);
    memset(lee, -1, sizeof(lee));
    citeste();
    Lee();
    afiseaza();
    return 0;
}

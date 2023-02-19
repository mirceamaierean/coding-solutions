#include <fstream>
#include <vector>
#include <string.h>
using namespace std;

vector<int> valori;

char camere[130][130];
int n, m, fil[130][130], maxi, cnt, curent;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

ifstream cin("vila.in");
ofstream cout("vila.out");

void citire()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> camere[i][j];
}

bool ok(int x, int y)
{
    if (x < 1 || y < 1 || x > n || y > m || fil[x][y] || camere[x][y] == '1')
        return false;
    return true;
}

void Fill(int i, int j)
{
    int x, y;
    fil[i][j] = curent;
    ++cnt;
    for (int k = 0; k < 4; ++k)
    {
        x = i + dx[k];
        y = j + dy[k];
        if (ok(x, y))
            Fill(x, y);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    valori.push_back(0);
    citire();
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (camere[i][j] == '-' && fil[i][j] == 0)
            {
                ++curent;
                cnt = 0;
                Fill(i, j);
                if (maxi < cnt)
                    maxi = cnt;
                valori.push_back(cnt);
            }

    cout << curent << "\n"
         << maxi << "\n";

    int x = 0, y = 0;
    maxi = 0;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (fil[i][j] == 0)
            {
                char viz[curent + 1];
                memset(viz, 0, sizeof(viz));
                cnt = 1;
                cnt += valori[fil[i - 1][j]];
                viz[fil[i - 1][j]] = 1;
                if (viz[fil[i][j - 1]] == 0)
                {
                    cnt += valori[fil[i][j - 1]];
                    viz[fil[i][j - 1]] = 1;
                }
                if (viz[fil[i + 1][j]] == 0)
                {
                    cnt += valori[fil[i + 1][j]];
                    viz[fil[i + 1][j]] = 1;
                }
                if (viz[fil[i][j + 1]] == 0)
                {
                    cnt += valori[fil[i][j + 1]];
                    viz[fil[i][j + 1]] = 1;
                }
                if (cnt > maxi)
                {
                    maxi = cnt;
                    x = i;
                    y = j;
                }
                else if (cnt == maxi && (i < x || (i == x && (i + j) < x + y)))
                {
                    maxi = cnt;
                    x = i;
                    y = j;
                }
            }

    cout << x << " " << y << " " << maxi << "\n";

    return 0;
}

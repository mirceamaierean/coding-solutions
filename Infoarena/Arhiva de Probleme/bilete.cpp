#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

ifstream fin("bilete.in");
ofstream fout("bilete.out");

char f[10][10][10][10][10][10];

int n, k;

inline bool ok(int x, int y)
{
    return f[x][y][0][0][0][0] == 0 && f[x][n - y + 1][0][0][0][0] == 0;
}

inline bool ok2(int x, int y, int x1, int y1)
{
    return f[x][y][x1][y1][0][0] == 0 && f[x1][n - y1 + 1][x][n - y + 1][0][0] == 0 && f[x][n - y + 1][x1][n - y1 + 1][0][0] == 0;
}

inline bool ok3(int x, int y, int x1, int y1, int x2, int y2)
{
    if (x == x2)
        return f[x][y][x1][y1][x2][y2] == 0 && f[x2][n - y2 + 1][x1][n - y1 + 1][x][n - y + 1] == 0;
    if (x1 == x2)
        return f[x][y][x1][y1][x2][y2] == 0 && f[x][n - y + 1][x2][n - y2 + 1][x1][n - y1 + 1] == 0;
    if (x == x1)
        return f[x][y][x1][y1][x2][y2] == 0 && f[x1][n - y1 + 1][x][n - y + 1][x2][n - y2 + 1] == 0;

    return f[x][y][x1][y1][x2][y2] == 0 && f[x][n - y + 1][x1][n - y1 + 1][x2][n - y2 + 1] == 0;
}
void back2(int x, int y)
{
    for (int j = y + 1; j <= n; ++j)
        if (ok2(x, y, x, j))
        {
            fout << x << y << x << j << "\n";
            f[x][y][x][j][0][0] = 1;
        }
        else
            break;

    for (int i = x + 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            if (ok2(x, y, i, j))
            {
                fout << x << y << i << j << "\n";
                f[x][y][i][j][0][0] = 1;
            }
            else
                break;
        }
}

void back3(int p, int x, int y, int x1, int y1)
{
    if (p == 3)
    {
        for (int j = y1 + 1; j <= n; ++j)
            if (ok3(x, y, x1, y1, x1, j))
            {
                fout << x << y << x1 << y1 << x1 << j << "\n";
                f[x][y][x1][y1][x1][j] = 1;
            }
            else
                break;

        for (int i = x1 + 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
            {
                if (ok3(x, y, x1, y1, i, j))
                {
                    fout << x << y << x1 << y1 << i << j << "\n";
                    f[x][y][x1][y1][i][j] = 1;
                }
                else
                    break;
            }
    }
    else if (p == 2)
    {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (i > x || (i == x && j > y))
                    back3(3, x, y, i, j);
    }
}

int main()
{
    fin >> n >> k;
    if (k == 1)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (ok(i, j))
                {
                    fout << i << j << "\n";
                    f[i][j][0][0][0][0] = 1;
                }
                else
                    break;
            }
        }
    }
    else if (k == 2)
    {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= (n >> 1) + (n & 1); ++j)
                back2(i, j);
    }
    else
    {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= (n >> 1) + (n & 1); ++j)
                back3(2, i, j, 0, 0);
    }

    return 0;
}

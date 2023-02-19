#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin("randuri.in");
ofstream fout("randuri.out");

const int NMAX = 103;

vector<string> v;

bool LCS(int x, int y)
{
    int lcs[NMAX][NMAX] = {0}, x_size = v[x].size() - 1, y_size = v[y].size() - 1;

    for (int i = x_size; i >= 0; --i)
        for (int j = y_size; j >= 0; --j)
            if (v[x][i] == v[y][j])
                lcs[i][j] = lcs[i + 1][j + 1] + 1;
            else
                lcs[i][j] = max(lcs[i + 1][j], lcs[i][j + 1]);

    return lcs[0][0] > 6;
}

string a;

bool ok;
int succ[NMAX], n, cnt;

void move(int t)
{
    for (int i = t; i <= n; i++)
        succ[i] = succ[i + 1];
}

int main()
{
    while (getline(fin, a))
    {
        v.push_back(a);
    }

    n = v.size() - 1;

    v.push_back("0");

    for (int i = 0; i <= n + 1; ++i)
        succ[i] = i;

    ok = 1;

    while (ok)
    {
        ok = 0;
        for (int i = 1; i < n; ++i)
        {
            if (LCS(succ[i - 1], succ[i + 1]))
            {
                move(i);
                ok = 1;
                ++cnt;
            }
        }
    }

    fout << cnt << "\n";

    return 0;
}

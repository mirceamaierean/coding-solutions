#include <fstream>

using namespace std;

int a[101][101], n;

void RoyFloyd()
{
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (a[i][k] && a[k][j] && (a[i][j] > a[i][k] + a[k][j] || !a[i][j]) && i != j)
                    a[i][j] = a[i][k] + a[k][j];
}

ifstream fin("royfloyd.in");
ofstream fout("royfloyd.out");

int main()
{
    ios_base::sync_with_stdio(0);
    fin.tie(NULL);
    fin >> n;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            fin >> a[i][j];

    RoyFloyd();

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            fout << a[i][j] << " ";
        fout << "\n";
    }

    return 0;
}

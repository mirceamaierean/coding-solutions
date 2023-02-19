#include <fstream>
#include <algorithm>
using namespace std;
ifstream cin("comori.in");
ofstream cout("comori.out");
int a[202][202], n, m;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
            a[i][j] += max(max(a[i - 1][j - 1], a[i - 1][j]), a[i - 1][j + 1]);
        }
    int max = 0;
    for (int j = 1; j <= m; ++j)
        if (a[n][j] > max)
            max = a[n][j];
    cout << max;
    return 0;
}

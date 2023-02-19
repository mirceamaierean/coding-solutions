#include <fstream>
#include <algorithm>
using namespace std;
ifstream cin("sumtri.in");
ofstream cout("sumtri.out");
int a[101][101], n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
        {
            cin >> a[i][j];
            a[i][j] += max(a[i - 1][j - 1], a[i - 1][j]);
        }
    int max = 0;
    for (int j = 1; j <= n; ++j)
        if (a[n][j] > max)
            max = a[n][j];
    cout << max;
    return 0;
}

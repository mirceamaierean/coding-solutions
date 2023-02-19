#include <iostream>
using namespace std;
int main()
{
    int n, i, j, a[21][21], dp = 0, ds = 0, D;
    cin >> n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            cin >> a[i][j];
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            if (i == j)
                dp = dp + a[i][j];
            if (i + j == n + 1)
                ds = ds + a[i][j];
        }
    if (dp > ds)
        D = dp - ds;
    else
        D = ds - dp;
    cout << D;
    return 0;
}
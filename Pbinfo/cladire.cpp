#include <fstream>
#define NMAX 1025
using namespace std;
ifstream cin("cladire.in");
ofstream cout("cladire.out");
int a[NMAX][NMAX];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
        a[1][i] = 1;
    for (int i = 2; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            a[i][j] = (a[i - 1][j] + a[i][j - 1]) % 9901;
    cout << a[n][m];
    return 0;
}

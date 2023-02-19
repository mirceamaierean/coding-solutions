#include <iostream>
using namespace std;
int a[20][20];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (i == 1 || j == 1 || i == n || j == n)
                a[i][j] = i + j;
            else
                a[i][j] = a[i - 1][j - 1] + a[i - 1][j] + a[i - 1][j + 1];
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

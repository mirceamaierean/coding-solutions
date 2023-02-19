#include <iostream>

using namespace std;

int mat[20][20], n;

int main()
{
    cin >> n;
    for (int j = 1; j <= n; ++j)
        mat[n][j] = j;

    for (int i = n - 1; i >= 1; --i)
        for (int j = 1; j <= i; ++j)
            mat[i][j] = mat[i + 1][j - 1] + mat[i + 1][j] + mat[i + 1][j + 1];

    for (int i = 1; i <= n; ++i, cout << '\n')
        for (int j = 1; j <= n; ++j)
            cout << mat[i][j] << " ";

    return 0;
}

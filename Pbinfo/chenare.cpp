#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cout << min(min(min(i, j), n - i + 1), n - j + 1) << " ";
        cout << "\n";
    }
    return 0;
}

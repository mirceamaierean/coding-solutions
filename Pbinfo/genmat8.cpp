#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            if (i % 2 == 1)
                cout << i << " ";
            else
                cout << j << " ";
        cout << "\n";
    }
    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    int n, m, val;
    cin >> n >> m;
    val = n * m;
    for (int i = n; i > 0; --i)
    {
        for (int j = m; j > 0; --j)
        {
            cout << val << " ";
            --val;
        }
        cout << "\n";
    }
    return 0;
}

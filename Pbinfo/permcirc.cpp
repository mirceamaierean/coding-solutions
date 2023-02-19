#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*ifstream cin("alfanumeric.in");
ofstream cout("alfanumeric.out");*/

int main()
{
    int v[20], n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < i + n; ++j)
            cout << v[j % n] << " ";
        cout << "\n";
    }
    return 0;
}

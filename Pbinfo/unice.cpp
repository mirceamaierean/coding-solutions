#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int v[101];
ifstream cin("unice.in");
ofstream cout("unice.out");
int main()
{
    int n;
    int a, max = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a;
        ++v[a];
        if (a > max)
            max = a;
    }
    for (int i = 0; i <= max; ++i)
        if (v[i] == 1)
            cout << i << " ";
    return 0;
}

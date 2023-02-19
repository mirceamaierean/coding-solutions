#include <fstream>
#include <limits.h>
using namespace std;
ifstream cin("maxmat.in");
ofstream cout("maxmat.out");
int main()
{
    int n, m, a;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        int max = INT_MIN, poz = 0;
        for (int j = 1; j <= m; ++j)
        {
            cin >> a;
            if (a > max)
            {
                max = a;
                poz = j;
            }
        }
        cout << max << " " << poz << "\n";
    }
    return 0;
}

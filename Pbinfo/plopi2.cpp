#include <fstream>
#include <limits.h>
using namespace std;
ifstream cin("plopi2.in");
ofstream cout("plopi2.out");
int main()
{
    int n, a, b = INT_MAX, cnt = 0, suma = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a;
        if (a > b)
        {
            ++cnt;
            suma += (a - b);
        }
        else
            b = a;
    }
    cout << cnt << " " << suma;
    return 0;
}

#include <fstream>
#include <string.h>
using namespace std;
int v[101];
int rl(int n, int p)
{
    int nr = 1;
    while (p > 0)
    {
        if (p % 2 == 1)
        {
            nr = (nr * n) % 10;
            p--;
        }
        else
        {
            n = (n * n) % 10;
            p = p / 2;
        }
    }
    return nr;
}
ifstream cin("cifra.in");
ofstream cout("cifra.out");
int main()
{
    for (int i = 1; i < 100; ++i)
        v[i] = (v[i - 1] + rl(i, i)) % 10;
    char a[105];
    int t, nr;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cin >> a;
        if (strlen(a) == 1)
            nr = a[strlen(a - 1)] - 48;
        else
            nr = (a[strlen(a) - 2] - 48) * 10 + (a[strlen(a) - 1] - 48);
        cout << v[nr] << "\n";
    }
    return 0;
}
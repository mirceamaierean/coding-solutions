#include <fstream>
#include <cmath>
using namespace std;
int divprim(int n)
{
    for (int i = 2; i <= sqrt(n); ++i)
        if (n % i == 0)
            return i;
    return n;
}
ifstream cin("nrdiv.in");
ofstream cout("nrdiv.out");
int main()
{
    int n, cnt = 1;
    cin >> n;
    int d, p;
    while (n > 1)
    {
        d = divprim(n);
        p = 0;
        while (n % d == 0)
        {
            n /= d;
            ++p;
        }
        cnt *= (p + 1);
    }
    cout << cnt;
    return 0;
}

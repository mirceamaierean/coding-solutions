#include <iostream>

using namespace std;

int main()
{
    int n, cnt = 0, nrfin = 0, nrimp = 1;
    cin >> n;
    while (n % 2 == 0)
    {
        ++cnt;
        n /= 2;
    }
    int d = 3;
    nrfin = cnt + 1;
    while (n > 1)
    {
        int p = 0;
        while (n % d == 0)
        {
            ++p;
            n /= d;
        }
        if (p)
        {
            nrfin *= (p + 1);
            nrimp *= (p + 1);
        }
        d += 2;
    }
    cout << nrfin - nrimp;
    return 0;
}

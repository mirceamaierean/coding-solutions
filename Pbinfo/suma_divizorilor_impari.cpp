#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, i, s = 1;
    cin >> n;
    int p = (int)sqrt(n);
    if (p * p == n && n % 2 == 1)
        s += p;
    for (i = 2; i <= p; ++i)
        if (n % i == 0)
        {
            if (i % 2 == 1)
            {
                s += i;
            }
            if (n % (n / i) == 0 && n / i % 2 == 1)
            {
                s += n / i;
            }
        }
    cout << s;
    return 0;
}

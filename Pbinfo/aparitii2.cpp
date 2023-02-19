#include <iostream>
#include <cmath>
using namespace std;

int firstDigit(int n)
{
    int digits = (int)log10(n);
    n = (int)(n / pow(10, digits));
    return n;
}
int main()
{
    int a, cnt = 0, n;
    cin >> a;
    if (a == 0)
        cout << 1;
    else
    {
        n = firstDigit(a);
        while (a)
        {
            if (n == a % 10)
                cnt++;
            a = a / 10;
        }
        cout << cnt;
    }
    return 0;
}

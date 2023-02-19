#include <iostream>

using namespace std;

int main()
{
    int n, i;
    long long S = 0;
    cin >> n;
    if (n == 0)
        cout << 0;
    else if (n == 1)
        cout << 1;
    else
    {
        for (i = 2; i * i <= n; i++)
            if (n % i == 0)
            {
                if (i * i != n)
                    S += i + n / i;
                else
                    S += i;
            }

        cout << S + 1 + n;
    }
    return 0;
}

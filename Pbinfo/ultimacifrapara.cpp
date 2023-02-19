#include <iostream>
using namespace std;

int main()
{
    unsigned long long n, cif = 1;
    cin >> n;
    if (n == 0)
        cout << 0;
    else
    {
        while (n)
        {
            if ((n % 10) % 2 == 0)
            {
                cif = n % 10;
                break;
            }
            n /= 10;
        }
        if (cif == 1)
            cout << -1;
        else
            cout << cif;
    }
    return 0;
}

#include <cmath>
int sum_div_prim(int n, int &suma)
{
    suma = 0;
    for (int i = 2; i < sqrt(n); ++i)
    {
        int y = i;
        if (n % y == 0)
        {
            bool ok = true;
            for (int j = 2; j <= sqrt(y); ++j)
                if (y % j == 0)
                {
                    ok = false;
                    break;
                }
            if (ok == true)
                suma += i;
        }
        y = n / i;
        {
            bool ok = true;
            for (int j = 2; j <= sqrt(y); ++j)
                if (y % j == 0)
                {
                    ok = false;
                    break;
                }
            if (ok == true)
                suma += i;
        }
    }
    if (sqrt(n) * sqrt(n) == n)
    {
        int y = sqrt(n);
        bool ok = true;
        for (int j = 2; j <= sqrt(y); ++j)
            if (y % j == 0)
            {
                ok = false;
                break;
            }
        if (ok == true)
            suma += sqrt(n);
    }
    if (suma == 0)
        suma = n;
    return suma;
}

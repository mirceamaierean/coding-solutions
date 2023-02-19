#include <cmath>
bool isprime(int a)
{
    for (int i = 2; i <= sqrt(a); ++i)
        if (a % i == 0)
            return 0;
    return 1;
}
bool a_prim(int a)
{
    for (int i = 2; i <= sqrt(a); ++i)
        if (a % i == 0 && isprime(i) && isprime(a / i) && i != a / i)
            return 1;
    return 0;
}

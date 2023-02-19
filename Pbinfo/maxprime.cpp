bool prim(int n)
{
    if (n == 2)
        return true;
    if ((n & 1) == 0)
        return false;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;
    return true;
}
void sub(int n, int &a, int &b)
{
    if ((n & 1) == 0)
        n--;
    else
        n -= 2;
    while (!prim(n))
        n -= 2;
    a = n;
    if (n == 3)
        b = 2;
    else
    {
        n -= 2;
        while (!prim(n))
            n -= 2;
        b = n;
    }
}
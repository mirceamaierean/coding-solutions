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
int i_prim(int n)
{
    int p1 = n, p2 = n;
    while (!prim(p1))
        p1--;
    while (!prim(p2))
        p2++;
    return p2 - p1;
}
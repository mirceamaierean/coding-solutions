void P(int &n, int c)
{
    int m = 0, p = 1;
    while (n)
    {
        if (n % 10 != c)
        {
            m += (p * (n % 10));
            p *= 10;
        }
        n /= 10;
    }
    n = m;
}
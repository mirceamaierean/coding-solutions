int prel(int p, int n)
{
    while (n)
    {
        p *= 10;
        n /= 10;
    }
    return p;
}
double nreal(int x, int y)
{
    int p = prel(1, y);
    double n = x * p + y;
    return n / p;
}
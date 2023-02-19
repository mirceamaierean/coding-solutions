int multipli(int &a, int &b, int c)
{
    while (a % c)
        ++a;
    while (b % c)
        --b;
    if (a > b)
        return 0;
    return (b - a) / c + 1;
}
int UCP(int n)
{
    if (n == 0)
        return 0;
    while (n)
    {
        if ((n & 1) == 0)
            return n % 10;
        n /= 10;
    }
    return -1;
}
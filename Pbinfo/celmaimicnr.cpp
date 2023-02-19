int cmmnr(int n)
{
    int fr[10] = {0};
    while (n)
    {
        fr[n % 10]++;
        n = n / 10;
    }
    for (int i = 1; i <= 9; i++)
        if (fr[i])
        {
            n = n * 10 + i;
            fr[i]--;
            break;
        }
    for (int i = 0; i <= 9; i++)
        while (fr[i])
        {
            n = n * 10 + i;
            fr[i]--;
        }
    return n;
}
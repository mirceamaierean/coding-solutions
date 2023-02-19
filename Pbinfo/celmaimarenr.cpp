int cmmnr(int n)
{
    int i, v[10] = {0}, cif, nou = 0;
    while (n)
    {
        cif = n % 10;
        v[cif]++;
        n /= 10;
    }
    for (cif = 9; cif >= 0; cif--)
    {
        for (i = 1; i <= v[cif]; i++)
            nou = nou * 10 + cif;
    }
    return nou;
}

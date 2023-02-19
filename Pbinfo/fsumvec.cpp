int suma(int v[], int n, int i, int j)
{
    int s = 0;
    for (int k = 1; k < i; ++k)
        s += v[k];
    for (int k = j + 1; k <= n; ++k)
        s += v[k];
    return s;
}
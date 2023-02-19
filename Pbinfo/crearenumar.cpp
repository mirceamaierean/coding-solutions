void F(int n, int a[], int &k)
{
    k = 0;
    bool ok = false;
    for (int i = 0; i < n; ++i)
        if (a[i] % 2 == 0)
        {
            ok = true;
            k *= 10;
            k += a[i];
        }
    if (!ok)
        k = -1;
}
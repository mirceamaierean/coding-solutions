int sum3(int v[], int n)
{
    int s(0);
    for (int i = 0; i < n; ++i)
        if (v[i] % 3 == 0)
            s += v[i];
    return s;
}
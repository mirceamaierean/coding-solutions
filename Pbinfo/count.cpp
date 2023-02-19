int count(double a[], int n)
{
    double suma = 0;
    for (int i = 0; i < n; ++i)
        suma += a[i];
    int cnt = 0;
    suma /= n;
    for (int i = 0; i < n; ++i)
        if (a[i] >= suma)
            cnt++;
    return cnt;
}
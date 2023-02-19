int interval(int a[], int n)
{
    if (n == 1)
        return 1;
    n--;
    int cnt = 2, c1 = a[0], c2 = a[n];
    if (c1 > c2)
        swap(c1, c2);
    for (int i = 1; i < n; ++i)
        if (a[i] >= c1 && a[i] <= c2)
            cnt++;
    return cnt;
}
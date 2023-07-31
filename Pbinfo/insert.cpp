void Insert(int a[], int &n)
{
    int k = n - 1;
    for(int i = 0; i < n; ++i)
        if(a[i] & 1) k++;
    int cop = k;
    for(int i = n - 1; i >= 0; --i)
    {
        if(a[i] & 1)
        {
            a[k] = 2 * a[i];
            k--;
        }
        a[k] = a[i];
        k--;
    }
    n = cop + 1;
}

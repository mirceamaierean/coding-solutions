#include <limits.h>
void numar(int n, int a[], int &k)
{
    long long min = INT_MAX, max = -1;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] > max)
            max = a[i];
        if (a[i] < min)
            min = a[i];
    }
    int cmin = min, cnt = 0;
    while (cmin)
    {
        cnt++;
        cmin /= 10;
    }
    for (int i = 1; i <= cnt; ++i)
        max *= 10;
    max += min;
    k = max;
}
#include <limits.h>

int nr_sa(int a[][100], int n, int m)
{
    int cmax[100], lmin[100], cmin[100], lmax[100];
    for(int i = 0; i < n; ++i)
    {
        lmin[i] = INT_MAX;
        lmax[i] = INT_MIN;
    }
    for(int j = 0; j < m; ++j)
    {
        cmin[j] = INT_MAX;
        cmax[j] = INT_MIN;
    }
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
        {
            if(a[i][j] > cmax[j]) cmax[j] = a[i][j];
            if(a[i][j] > lmax[i]) lmax[i] = a[i][j];
            if(a[i][j] < lmin[i]) lmin[i] = a[i][j];
            if(a[i][j] < cmin[j]) cmin[j] = a[i][j];
        }
    int cnt = 0;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if((a[i][j] == lmin[i] && a[i][j] == cmax[j]) || (a[i][j] == lmax[i] && a[i][j] == cmin[j])) cnt++;
    return cnt;
}

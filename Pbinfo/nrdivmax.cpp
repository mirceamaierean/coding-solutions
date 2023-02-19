#include <iostream>
#include <string.h>
using namespace std;
int ndiv[100001];
int main()
{
    int n, dmax = 1, max = 1;
    cin >> n;
    for (int i = 2; i <= n; ++i)
        for (int j = i; j <= n; j += i)
        {
            ++ndiv[j];
            if (ndiv[j] > dmax)
            {
                dmax = ndiv[j];
                max = j;
            }
        }
    cout << max;
    return 0;
}

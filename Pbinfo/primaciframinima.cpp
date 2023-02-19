#include <iostream>
#include <limits.h>
using namespace std;

int main()
{
    int n, a, cop, cifmin = 9, min = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a;
        cop = a;
        while (cop > 9)
        {
            cop /= 10;
        }
        if (cop < cifmin)
        {
            cifmin = cop;
            min = a;
        }
        else if (cop == cifmin)
        {
            if (a > min)
                min = a;
        }
    }
    cout << min;
    return 0;
}

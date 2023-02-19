#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int a, n, max = 0, cnt, k;
    cin >> n >> a;
    for (int i = 1; i < n; ++i)
    {
        cin >> k;
        if (abs(a - k) > max)
        {
            max = abs(a - k);
            cnt = 1;
        }
        else if (abs(a - k) == max)
            ++cnt;
        a = k;
    }
    cout << max << " " << cnt;
    return 0;
}

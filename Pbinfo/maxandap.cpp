#include <iostream>
using namespace std;

int main()
{
    int n, a, max = 0, cnt = 0, best = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a;
        if (a > max)
        {
            max = a;
            cnt = 1;
        }
        else if (a == max)
            ++cnt;
        if (cnt > best)
            best = cnt;
    }
    cout << max << " " << best;
    return 0;
}

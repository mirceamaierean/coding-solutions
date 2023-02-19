#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, a, b, max = 0, af1, af2;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a >> b;
        if (abs(a - b) > max)
        {
            max = abs(a - b);
            af1 = a;
            af2 = b;
        }
    }
    cout << af1 << " " << af2;
    return 0;
}

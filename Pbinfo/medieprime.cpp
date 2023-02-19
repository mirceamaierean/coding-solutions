#include <iostream>
#include <iomanip>
#include <bitset>
using namespace std;
bitset<10005> ciur;
int main()
{
    ciur[0] = 1;
    ciur[1] = 1;
    for (int i = 4; i <= 10000; i += 2)
        ciur[i] = 1;
    for (int i = 3; i <= 5000; i += 2)
        if (ciur[i] == 0)
            for (int j = i + i; j <= 10000; j += i)
                ciur[j] = 1;
    double suma = 0.00;
    int n, a, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a;
        if (ciur[a] == 0)
        {
            suma += a;
            ++cnt;
        }
    }
    cout << fixed << setprecision(2) << suma / cnt - 0.01;
    return 0;
}

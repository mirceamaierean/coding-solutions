#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int c1 = sqrt(n);
    while (n % c1)
        --c1;
    cout << c1 << " " << n / c1;
    return 0;
}

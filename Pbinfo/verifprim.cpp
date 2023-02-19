#include <iostream>
#include <cmath>
using namespace std;
bool prim(int n)
{
    for (int i = 2; i <= sqrt(n); ++i)
        if (n % i == 0)
            return 0;
    return 1;
}
int main()
{
    int n;
    cin >> n;
    if (n && prim(n) && n != 1)
        cout << "DA";
    else
        cout << "NU";
    return 0;
}

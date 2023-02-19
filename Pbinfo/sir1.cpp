#include <iostream>

using namespace std;

int main()
{
    int n, i = 1;
    cin >> n;
    while (i < n)
    {
        n -= i;
        ++i;
    }
    cout << i - n + 1;
    return 0;
}

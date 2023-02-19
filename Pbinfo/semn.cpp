#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n == 0)
        cout << "nul";
    else if (n > 0)
        cout << "pozitiv";
    else
        cout << "negativ";
    return 0;
}

#include <iostream>
using namespace std;

int main()
{
    char a[20];
    cin.getline(a, 20);
    cout << a[0] + a[1] - 96;
    return 0;
}

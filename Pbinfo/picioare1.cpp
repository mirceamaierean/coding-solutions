#include <iostream>

using namespace std;

int main()
{
    int a, b, g, o;
    cin >> a >> b;
    a *= 2;
    o = (b - a) / 2;
    a /= 2;
    g = a - o;
    cout << g << " " << o;
    return 0;
}

#include <fstream>
using namespace std;
ifstream cin("maxim.in");
ofstream cout("maxim.out");
int main()
{
    int a, b;
    cin >> a >> b;
    if (a > b)
        swap(a, b);
    cout << b;
    return 0;
}

#include <fstream>
#include <algorithm>
using namespace std;
ifstream cin("maxim3.in");
ofstream cout("maxim3.out");
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << max(max(a, b), c);
    return 0;
}

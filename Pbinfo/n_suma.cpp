#include <fstream>
#include <cmath>
using namespace std;
ifstream cin("n_suma.in");
ofstream cout("n_suma.out");
int main()
{
    int n, suma = 0, a;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a;
        suma += a;
    }
    cout << suma;
    return 0;
}

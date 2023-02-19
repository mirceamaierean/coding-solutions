#include <fstream>
#include <limits.h>
using namespace std;
ifstream cin("secvmax.in");
ofstream cout("secvmax.out");
int main()
{
    int n, a, cop = 0, suma = 0, cnt = 0, best = 0, poz = 0, bestsum = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a;
        if (a % 2 == 0)
        {
            ++cnt;
            suma += a;
        }
        else
        {
            cnt = 0;
            suma = 0;
        }
        if (cnt > best)
        {
            best = cnt;
            bestsum = suma;
            poz = i - cnt + 1;
        }
        else if (cnt == best && bestsum < suma)
        {
            best = cnt;
            bestsum = suma;
            poz = i - cnt + 1;
        }
    }
    cout << poz << " " << poz - 1 + best;
    return 0;
}

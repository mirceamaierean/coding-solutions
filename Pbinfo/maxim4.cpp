#include <fstream>
using namespace std;
ifstream cin("maxim4.in");
ofstream cout("maxim4.out");
int main()
{
    int n, a, max = 0, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a;
        if (a == max)
            ++cnt;
        else if (a > max)
        {
            max = a;
            cnt = 1;
        }
    }
    cout << max << " " << cnt;
    return 0;
}

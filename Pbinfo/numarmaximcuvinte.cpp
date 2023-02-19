#include <fstream>
#include <string.h>
using namespace std;
ifstream cin("cuvmax.in");
ofstream cout("cuvmax.out");
int main()
{
    string a, m;
    int n, max = 0, val;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int cnt = 0;
        getline(cin, a);
        for (int i = 0; i < a.length(); ++i)
            if (a[i] != ' ' && a[i + 1] == ' ')
                ++cnt;
        if (cnt >= max)
        {
            max = cnt;
            m = a;
        }
    }
    cout << m;
    return 0;
}

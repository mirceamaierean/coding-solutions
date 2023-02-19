#include <fstream>

using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int main()
{
    int n, a, b;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a >> b;
        int r = 1;
        if (a < b)
            swap(a, b);
        while (r)
        {
            r = a % b;
            a = b;
            b = r;
        }
        cout << a << "\n";
    }
    return 0;
}

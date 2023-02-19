#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> par;
vector<int> impar;
ifstream cin("halfsort2.in");
ofstream cout("halfsort2.out");
int main()
{
    int n, a;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a;
        if (i % 2)
            impar.push_back(a);
        else
            par.push_back(a);
    }
    sort(par.begin(), par.end());
    sort(impar.begin(), impar.end());
    for (int i = 0; i < n; ++i)
        if (i % 2 == 0)
            cout << impar[(n - i) / 2 - 1] << " ";
        else
            cout << par[i / 2] << " ";
    return 0;
}

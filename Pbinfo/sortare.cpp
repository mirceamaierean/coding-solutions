#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> par;
ifstream cin("sortare.in");
ofstream cout("sortare.out");
int main()
{
    int n, a;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a;
        par.push_back(a);
    }
    sort(par.begin(), par.end());
    for (int i = n - 1; i >= 0; --i)
        cout << par[i] << " ";
    return 0;
}

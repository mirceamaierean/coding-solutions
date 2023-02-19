#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream cin("masini.in");
ofstream cout("masini.out");
vector<int> v;
int main()
{
    int n, a, sum = 0, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    int i = 0;
    do
    {
        sum += v[i];
        ++i;
    } while (sum <= k);
    cout << i - 1;
    return 0;
}

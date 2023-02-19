#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v;
ifstream cin("cifreord.in");
ofstream cout("cifreord.out");
int main()
{
    int n, p;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> p;
        v.push_back(p);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i += 20)
    {
        for (int j = i; j < i + 20 && j < n; ++j)
            cout << v[j] << " ";
        cout << '\n';
    }
    return 0;
}

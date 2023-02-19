#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
ifstream cin("interclasare2.in");
ofstream cout("interclasare2.out");
int main()
{
    vector<int> v;
    vector<int> afis;
    int n, a, j = 0, i;
    cin >> n;
    for (i = 1; i <= n; ++i)
    {
        cin >> a;
        v.push_back(a);
    }
    cin >> n;
    for (i = 1; i <= n; ++i)
    {
        cin >> a;
        if (binary_search(v.begin(), v.end(), a))
            afis.push_back(a);
    }
    n = afis.size();
    for (i = 0; i < n - 10; i += 10)
    {
        for (j = i; j < i + 10; ++j)
            cout << afis[j] << " ";
        cout << "\n";
    }
    for (i = j; i < n; ++i)
        cout << afis[i] << " ";
    return 0;
}

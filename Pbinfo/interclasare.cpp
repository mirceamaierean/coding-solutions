#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
ifstream cin("interclasare.in");
ofstream cout("interclasare.out");
int main()
{
    vector<int> v;
    int n, a, j, i;
    cin >> n;
    int fin = n;
    for (i = 1; i <= n; ++i)
    {
        cin >> a;
        v.push_back(a);
    }
    cin >> n;
    fin += n;
    for (i = 1; i <= n; ++i)
    {
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    for (i = 0; i <= fin - 10; i += 10)
    {
        for (j = i; j < i + 10; ++j)
            cout << v[j] << " ";
        cout << "\n";
    }
    for (i = j; i < fin; ++i)
        cout << v[i] << " ";
    return 0;
}

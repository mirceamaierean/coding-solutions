#include <fstream>
#include <set>
using namespace std;
set<int> inter;
ifstream cin("interclasare1.in");
ofstream cout("interclasare1.out");
int main()
{
    int n, m, a;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a;
        inter.insert(a);
    }
    cin >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a;
        inter.insert(a);
    }
    set<int>::iterator it;
    int cnt = 0;
    for (it = inter.begin(); it != inter.end(); ++it)
    {
        cout << *it << " ";
        ++cnt;
        if (cnt % 10 == 0)
            cout << "\n";
    }
    return 0;
}

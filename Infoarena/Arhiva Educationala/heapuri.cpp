#include <fstream>
#include <set>
#define NMAX 200005
using namespace std;
int n, a[NMAX], k = 1, q, v;
ifstream cin("heapuri.in");
ofstream cout("heapuri.out");
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    set<int> s;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> q;
        if (q == 3)
            cout << *s.begin() << "\n";
        else
        {
            cin >> v;
            if (q == 1)
            {
                a[k] = v;
                s.insert(v);
                k++;
            }
            else
                s.erase(a[v]);
        }
    }
    return 0;
}

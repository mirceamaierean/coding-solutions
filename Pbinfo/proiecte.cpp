#include <fstream>
#include <vector>
using namespace std;
ifstream cin("proiecte.in");
ofstream cout("proiecte.out");
vector<int> a;
vector<int> b;
int main()
{
    int k, n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> k;
        a.push_back(k);
        b.push_back(i);
    }
    for (int i = 0; i < n - 1; ++i)
        for (int j = i; j < n; ++j)
            if (a[i] > a[j])
            {
                swap(a[i], a[j]);
                swap(b[i], b[j]);
            }
    for (int i = 0; i < n; ++i)
        cout << b[i] << " ";
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int main()
{
    int n, x, p, a;
    cin >> n >> p >> x;
    for (int i = 1; i < x; ++i)
    {
        cin >> a;
        v.push_back(a);
    }
    v.push_back(p);
    for (int i = x; i <= n; ++i)
    {
        cin >> a;
        v.push_back(a);
    }
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    return 0;
}

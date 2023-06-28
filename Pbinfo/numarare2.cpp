#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int main()
{
    int n,a;
    double m=0;

    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        cin >> a;
        m += a;
        v.push_back(a);
    }

    m /= n;

    int cnt = 0;

    for(int i = 0; i < n; ++i)
    	if (v[i] > m) ++cnt;
    cout << cnt;
    return 0;
}

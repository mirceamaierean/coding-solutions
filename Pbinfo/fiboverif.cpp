#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<unsigned long long> v;
int main()
{
    v.push_back(1);
    v.push_back(1);
    for (int i = 2; i <= 60; ++i)
    {
        v.push_back(v[i - 2] + v[i - 1]);
    }
    int n, a;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a;
        if (binary_search(v.begin(), v.end(), a))
            cout << "DA\n";
        else
            cout << "NU\n";
    }
    return 0;
}

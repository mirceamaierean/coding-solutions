#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int main()
{
    int n;
    cin >> n;
    while (n)
    {
        v.push_back(n % 10);
        n /= 10;
    }
    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = 0; j < v.size(); ++j)
            cout << v[j] << " ";
        cout << "\n";
    }
    return 0;
}

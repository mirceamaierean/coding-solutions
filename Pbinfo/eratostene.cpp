#include <fstream>
#include <limits.h>
#include <bitset>
#include <vector>
using namespace std;
bitset<1000000> ciur;
int main()
{
    ifstream cin("eratostene.in");
    ofstream cout("eratostene.out");
    int n, i, cnt = 0;
    std::vector<int> s(1000001);
    cin >> n;
    int max = INT_MIN;
    for (i = 1; i <= n; ++i)
    {
        cin >> s[i];
        if (s[i] > max)
            max = s[i];
    }
    ciur[1] = 1;
    for (i = 2; i <= max; ++i)
        if (ciur[i] == 0)
            for (int j = i + i; j <= max; j += i)
                ciur[j] = 1;
    for (i = 1; i <= n; ++i)
        if (ciur[s[i]] == 0)
            cnt++;
    cout << cnt;
    return 0;
}

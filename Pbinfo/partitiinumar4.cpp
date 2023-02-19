#include <fstream>
#include <algorithm>
int n, k, p;
using namespace std;
ifstream cin("partitiinumar4.in");
ofstream cout("partitiinumar4.out");
int v[50], a[50];
void afisare(int p)
{
    for (int i = 1; i <= p; ++i)
        cout << v[i] << " ";
    cout << '\n';
}
int valid(int p)
{
    int sum = 0;
    for (int i = 1; i <= p; ++i)
    {
        sum += v[i];
        if (v[i] < v[i - 1])
            return 2;
    }
    if (sum > n)
        return 2;
    if (sum < n)
        return 0;
    if (sum == n)
        return 1;
}
void back(int p)
{
    for (int i = 1; i <= k; ++i)
    {
        v[p] = a[i];
        if (valid(p) == 1)
            afisare(p);
        if (valid(p) == 0)
            back(p + 1);
    }
}

int main()
{

    cin >> n >> k;
    for (int i = 1; i <= k; ++i)
        cin >> a[i];
    sort(a + 1, a + k + 1);
    back(1);
    return 0;
}

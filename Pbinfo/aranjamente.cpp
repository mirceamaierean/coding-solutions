#include <fstream>
#include <cmath>
int n, k;
using namespace std;
ifstream cin("aranjamente.in");
ofstream cout("aranjamente.out");
int v[50];
void afisare(int p)
{
    for (int i = 1; i <= p; ++i)
        cout << v[i] << " ";
    cout << "\n";
}
bool valid(int p)
{
    for (int i = 1; i < p; ++i)
        if (v[i] == v[p])
            return false;
    return true;
}
void back(int p)
{
    int pval;
    for (pval = 1; pval <= n; ++pval)
    {
        v[p] = pval;
        if (valid(p))
        {
            if (p == k)
                afisare(p);
            else
                back(p + 1);
        }
    }
}
int main()
{

    cin >> n >> k;
    back(1);
    return 0;
}

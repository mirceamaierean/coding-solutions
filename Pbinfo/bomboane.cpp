#include <fstream>
#include <vector>
#include <limits.h>
using namespace std;
vector<int> mare;
vector<int> mic;
vector<int> dedat;
ifstream cin("bomboane.in");
ofstream cout("bomboane.out");
int main()
{
    int sum = 0, max = INT_MIN, min = INT_MAX, n, a[1001];
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if (a[i] > max)
            max = a[i];
        if (a[i] < min)
            min = a[i];
        sum += a[i];
    }
    if (sum % n != 0)
    {
        cout << -1;
        return 0;
    }
    else
    {
        int r = sum / n, j = 0;
        while (min < r)
        {
            int d = r - min;
            dedat.push_back(d);
            for (int i = 1; i <= n; ++i)
                if (a[i] == max)
                {
                    a[i] -= d;
                    mare.push_back(i);
                    break;
                }
            for (int i = 1; i <= n; ++i)
                if (a[i] == min && mare[j] != i)
                {
                    a[i] += d;
                    mic.push_back(i);
                    break;
                }
            ++j;
            max = INT_MIN;
            min = INT_MAX;
            for (int i = 1; i <= n; ++i)
            {
                if (a[i] > max)
                    max = a[i];
                if (a[i] < min)
                    min = a[i];
            }
        }
        cout << dedat.size() << "\n";
        for (int i = 0; i < mic.size(); ++i)
            cout << mare[i] << " " << mic[i] << " " << dedat[i] << "\n";
    }
    return 0;
}

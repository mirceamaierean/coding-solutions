#include <fstream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <vector>

using namespace std;

ifstream fin("sume.in");
ofstream fout("sume.out");

const int PMAX = 25005;
int p, n, x1, x2, x3, s[PMAX];

vector<int> sol;
unordered_map<int, int> mp;

bool check(int ind)
{
    x1 = (s[1] + s[2] - s[ind]) / 2;
    x2 = s[1] - x1;
    x3 = s[2] - x1;

    if (x2 + x3 != s[ind] || (s[1] + s[2] - s[ind]) % 2)
        return 0;

    mp.clear();

    for (int i = 1; i <= p; i++)
        mp[s[i]] = 0;

    for (int i = 3; i <= p; i++)
        mp[s[i]]++;

    mp[s[ind]]--;

    sol.clear();

    sol.push_back(x1);
    sol.push_back(x2);
    sol.push_back(x3);

    for (int i = 3; i <= p; i++)
        if (mp[s[i]] > 0)
        {
            for (int x : sol)
            {
                mp[x + s[i] - x1]--;
                if (mp[x + s[i] - x1] < 0)
                    return 0;
            }
            sol.push_back(s[i] - x1);
        }
    return 1;
}
int main()
{
    fin >> p;
    for (int i = 1; i <= p; i++)
        fin >> s[i];
    sort(s + 1, s + p + 1);
    n = sqrt(2 * p) + 1;
    if (n * (n - 1) != 2 * p)
    {
        fout << "-1\n";
        return 0;
    }
    for (int i = 3; i <= n; i++)
        if (check(i) && sol.size() == n)
        {
            fout << n << "\n";
            for (int x : sol)
                fout << x << " ";
            return 0;
        }
    fout << "-1\n";

    return 0;
}
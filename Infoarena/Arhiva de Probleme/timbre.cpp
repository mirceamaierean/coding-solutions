#include <fstream>
#include <queue>
#include <vector>
using namespace std;

const int NMAX = 1005;

vector<int> v[NMAX];
priority_queue<int, vector<int>, greater<int>> q;

ifstream fin("timbre.in");
ofstream fout("timbre.out");

int n, m, k, a, b, cnt, ans;

int main()
{
    fin >> n >> m >> k;

    while (m--)
    {
        fin >> a >> b;
        if (a > n)
            q.push(b);
        else
            v[a].push_back(b);
    }

    cnt = k;

    for (int i = n; i >= 1; --i)
    {
        for (size_t j = 0; j < v[i].size(); ++j)
            q.push(v[i][j]);

        if (cnt == k)
        {
            cnt = 0;
            ans += q.top();
            q.pop();
        }
        ++cnt;
    }

    fout << ans << "\n";

    return 0;
}

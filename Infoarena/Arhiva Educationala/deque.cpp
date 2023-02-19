#include <fstream>
#include <deque>
#define ll long long
using namespace std;

ifstream fin("deque.in");
ofstream fout("deque.out");

deque<pair<int, int>> q;
int a, n, k;
ll s;

int main()
{
    ios_base::sync_with_stdio(0);
    fin.tie(NULL);
    fin >> n >> k;

    for (int i = 0; i < n; ++i)
    {
        fin >> a;

        while (!q.empty() && a < q.back().first)
            q.pop_back();

        q.push_back(make_pair(a, i));

        if (i - q.front().second == k)
            q.pop_front();
        if (i >= k - 1)
            s += q.front().first;
    }

    fout << s << "\n";
    return 0;
}

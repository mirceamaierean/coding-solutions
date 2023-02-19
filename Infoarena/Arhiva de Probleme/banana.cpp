#include <fstream>
#include <algorithm>
#include <map>
#include <queue>

std::ifstream fin("banana.in");
std::ofstream fout("banana.out");

typedef std::pair<int, int> p;

std::map<p, int> P;

const int NMAX = 16e3 + 1;

int t[NMAX], n, k, count[NMAX];

p x[NMAX];

int find(int a)
{
    if (a == t[a])
        return a;
    return t[a] = find(t[a]);
}

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main()
{
    fin >> n >> k;

    for (int i = 1; i <= n; ++i)
    {
        fin >> x[i].first >> x[i].second;
        P[x[i]] = i;
        t[i] = i;
        count[i] = 1;
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            p y = {x[i].first + dx[j], x[i].second + dy[j]};
            if (P.find(y) != P.end())
            {
                int r1 = find(i), r2 = find(P[y]);
                if (r1 < r2)
                {
                    count[r1] += count[r2];
                    count[r2] = 0;
                    t[r2] = r1;
                }
                else if (r1 > r2)
                {
                    count[r2] += count[r1];
                    count[r1] = 0;
                    t[r1] = r2;
                }
            }
        }
    }

    int s(0);

    std::sort(count + 1, count + n + 1, std::greater<int>());

    for (int i = 1; i <= k; ++i)
        s += count[i];

    fout << s << "\n";

    return 0;
}

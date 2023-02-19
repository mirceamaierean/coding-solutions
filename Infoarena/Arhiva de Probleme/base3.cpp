#include <fstream>
#include <queue>
#include <vector>
#include <string.h>
#include <math.h>
#include <stdlib.h>

std::ifstream fin("base3.in");
std::ofstream fout("base3.out");

typedef std::pair<int, int> p;

std::priority_queue<p, std::vector<p>, std::greater<p>> q;

const int NMAX = 16e3 + 2;
const int oo = 0x3f3f3f3f;

int dp[NMAX << 1], length_a, length_b, length_c;
std::string a, b, c;

inline int my_abs(int a)
{
    if (a < 0)
        return -a;
    return a;
}

void set_dp(std::string &s)
{
    for (int i = 0; s[i]; ++i)
        if (s[i] == '1')
        {
            int index = my_abs(i - (s.size() - i - 1));
            if (s.size() < dp[index])
                dp[index] = s.size();
        }
}

void next_edge(int &index, int &cost)
{
    if (index < (NMAX << 1) && dp[index] > cost)
    {
        q.push({cost, index});
        dp[index] = cost;
    }
}

void add_next(int &cost, int &node, int &length)
{
    int n_value = cost + length, n_index = node + length;

    next_edge(n_index, n_value);

    n_index = my_abs(node - length);

    next_edge(n_index, n_value);
}

void Dijkstra()
{
    while (!q.empty())
    {
        p crt = q.top();
        q.pop();

        if (crt.first > dp[crt.second])
            continue;

        if (crt.second == 0)
            return;

        add_next(crt.first, crt.second, length_a);
        add_next(crt.first, crt.second, length_b);
        add_next(crt.first, crt.second, length_c);
    }
}

int main()
{
    fin >> a >> b >> c;

    length_a = a.length();
    length_b = b.length();
    length_c = c.length();

    memset(dp, oo, sizeof dp);

    set_dp(a);
    set_dp(b);
    set_dp(c);

    for (int i = 0; i < (NMAX << 1); ++i)
        if (dp[i] != oo)
            q.push({dp[i], i});

    Dijkstra();

    if (dp[0] == oo)
        dp[0] = 0;

    fout << dp[0] << '\n';

    fout.close();
    return 0;
}

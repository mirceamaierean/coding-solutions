#include <fstream>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;

class InParser
{
#pragma warning(disable : 4996)
private:
    FILE *fin;
    char *buff;
    int sp;
    char read()
    {
        ++sp;
        if (sp == 4096)
        {
            sp = 0;
            fread(buff, 1, 4096, fin);
        }
        return buff[sp];
    }

public:
    InParser(const char *nume)
    {
        sp = 4095;
        buff = new char[4096];
        fin = fopen(nume, "r");
    }
    InParser &operator>>(int &n)
    {
        char c;
        while (!isdigit(c = read()))
            ;
        n = c - '0';
        while (isdigit(c = read()))
            n = n * 10 + c - '0';
        return *this;
    }
};

InParser fin("cezar.in");
ofstream fout("cezar.out");

const int NMAX = 1e4 + 1;

int cost[NMAX], n, k, a, b;

set<int> s[NMAX];

bitset<NMAX> used;

struct cmp
{
    inline bool operator()(int a, int b)
    {
        return cost[a] > cost[b];
    }
};

priority_queue<int, vector<int>, cmp> q;

int main()
{
    fin >> n >> k;

    for (int i = 1; i < n; ++i)
    {
        fin >> a >> b;
        s[a].insert(b);
        s[b].insert(a);
        cost[a] = 1;
        cost[b] = 1;
    }

    for (int i = 1; i <= n; ++i)
        if (s[i].size() == 1)
        {
            q.push(i);
            used[i] = 1;
        }

    k = n - k - 1;

    int sum = 0;

    while (k--)
    {
        int j = q.top();
        sum += cost[j];
        q.pop();
        for (auto i : s[j])
        {
            s[i].erase(j);
            cost[i] += cost[j];
            if (s[i].size() == 1 && used[i] == 0)
            {
                q.push(i);
                used[i] = 1;
            }
        }
    }

    fout << sum << "\n";
    fout.close();
    return 0;
}

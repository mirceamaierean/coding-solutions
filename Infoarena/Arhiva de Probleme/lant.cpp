#include <fstream>
#include <vector>
#include <string.h>
#include <bitset>
#pragma warning(disable : 4996)

std::ifstream fin("lant.in");
std::ofstream fout("lant.out");

const char del[] = " ,:;.!?-)";
const int NMAX = 155;

std::vector<std::string> VS;
std::vector<int> g[NMAX];
int k;

void add(std::string a)
{
    for (auto s : VS)
        if (s == a)
            return;

    VS.push_back(a);
}

bool ok(int x, int y)
{
    int dp[50][50] = {0};

    for (int i = 1; VS[x][i - 1]; ++i)
        dp[i][0] = i;

    for (int j = 1; VS[y][j - 1]; ++j)
        dp[0][j] = j;

    for (int i = 1; VS[x][i - 1]; ++i)
        for (int j = 1; VS[y][j - 1]; ++j)
        {
            dp[i][j] = 1 + std::min(dp[i - 1][j], dp[i][j - 1]);
            if (VS[x][i - 1] == VS[y][j - 1])
            {
                dp[i][j] = std::min(dp[i][j], dp[i - 1][j - 1]);
            }
        }

    return dp[VS[x].size()][VS[y].size()] <= k;
}

std::bitset<NMAX> used;

int lant[NMAX];

void DFS(int node)
{
    used[node] = 1;
    lant[node] = 0;

    for (auto i : g[node])
    {
        if (!used[i])
            DFS(i);

        lant[node] += lant[i];
    }
    lant[node] = std::max(lant[node], 1);
}

int main()
{
    char s[1002];

    fin >> k;

    while (fin.getline(s, 1002))
    {
        char *p = strtok(s, del);
        while (p)
        {
            std::string a(p);
            add(a);
            p = strtok(NULL, del);
        }
    }

    for (int i = 0; i < VS.size(); ++i)
        for (int j = i + 1; j < VS.size(); ++j)
            if (ok(i, j))
                g[i].push_back(j);

    DFS(0);

    fout << lant[0] << "\n";

    return 0;
}

#include <fstream>
#include <bitset>
#include <algorithm>
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

InParser fin("note.in");
std::ofstream fout("note.out");

const int NMAX = 1030;

std::bitset<NMAX> k[NMAX];

int dp[NMAX][NMAX], n, m, v, s[NMAX];

int main()
{
    fin >> v >> n;

    for (int i = 1; i <= v; ++i)
        for (int j = 1; j <= n; ++j)
        {
            fin >> m;
            k[m][j] = 1;
        }

    fin >> m;
    for (int i = 1; i <= m; ++i)
    {
        fin >> s[i];
        dp[0][i] = i;
    }

    for (int i = 1; i <= n; ++i)
        dp[i][0] = i;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (k[s[j]][i])
                dp[i][j] = dp[i - 1][j - 1];

            else
                dp[i][j] = std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;

    fout << dp[n][m] << "\n";

    fout.close();
    return 0;
}

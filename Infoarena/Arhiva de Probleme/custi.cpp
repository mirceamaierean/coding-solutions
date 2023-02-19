#include <fstream>
#include <string.h>
#include <algorithm>
#define NMAX 1005
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
InParser fin("custi.in");
ofstream fout("custi.out");

int fr[NMAX], dp[NMAX][NMAX], n;

int main()
{
    fin >> n;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            fin >> dp[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (dp[i][j])
            {
                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                fr[dp[i][j]]++;
            }
    for (int i = n; i; i--)
        fr[i] += fr[i + 1];
    for (int i = 1; i <= n; ++i)
        fout << fr[i] << "\n";
    return 0;
}

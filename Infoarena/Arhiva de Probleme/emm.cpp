#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

ifstream fin("emm.in");
ofstream fout("emm.out");

string s;
int i;

int eval();
int eval1()
{
    int r = eval();
    while (s[i] && (s[i] == 'm' || s[i] == 'M'))
    {
        if (s[i] == 'm')
        {
            i++;
            r = min(r, eval());
        }
        else
        {
            i++;
            r = max(r, eval());
        }
    }
    return r;
}

int eval()
{
    int r = 0;
    if (s[i])
    {
        if (s[i] == '(')
        {
            ++i;
            r = eval1();
            ++i;
        }
        else
            while (s[i] && isdigit(s[i]))
            {
                r = r * 10 + s[i] - '0';
                ++i;
            }
    }
    return r;
}
int main()
{
    fin >> s;
    fout << eval1() << "\n";
    return 0;
}

#include <fstream>

using namespace std;

ifstream fin("evaluare.in");
ofstream fout("evaluare.out");

char s[100005], *p = s;
int i;

int eval2();
int eval1();
int eval()
{
    int r = eval1();
    while (*p == '+' || *p == '-')
        if (*p == '+')
        {
            ++p;
            r += eval1();
        }
        else
        {
            ++p;
            r -= eval1();
        }
    return r;
}
int eval1()
{
    int r = eval2();
    while (*p == '*' || *p == '/')
        if (*p == '*')
        {
            ++p;
            r *= eval2();
        }
        else
        {
            ++p;
            r /= eval2();
        }
    return r;
}
int eval2()
{
    int r = 0;
    if (*p == '(')
    {
        ++p;
        r = eval();
        ++p;
    }
    else
        while (isdigit(*p))
        {
            r = r * 10 + *p - '0';
            ++p;
        }
    return r;
}
int main()
{
    fin >> s;
    fout << eval() << "\n";
    return 0;
}

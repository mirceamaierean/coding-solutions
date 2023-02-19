
#include <fstream>

using namespace std;

ifstream fin("tort.in");
ofstream fout("tort.out");

long long r[51];

void prod(long long n)
{
    long long t = 0;
    for (int i = 1; i <= r[0]; ++i, t /= 10)
    {
        t += r[i] * n;
        r[i] = t % 10;
    }

    while (t)
    {
        r[++r[0]] = t % 10;
        t /= 10;
    }
}

void div()
{
    long long t = 0;
    for (int i = r[0]; i; --i)
    {
        t = t * 10 + r[i];
        r[i] = (t >> 1);
        t = (t & 1);
    }
    while (r[0] > 1 && r[r[0]] == 0)
    {
        --r[0];
    }
}

int main()
{
    long long a, b;
    fin >> a >> b;
    r[0] = r[1] = 1;
    prod(a + 1);
    prod(b + 1);
    prod(a + b + 2);
    div();
    for (int i = r[0]; i; --i)
        fout << r[i];

    return 0;
}
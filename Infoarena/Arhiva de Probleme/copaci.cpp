#include <fstream>
#include <cmath>
using namespace std;

ifstream fin("copaci.in");
ofstream fout("copaci.out");

struct punct
{
    long long x, y;
};

long long __gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    a %= b;
    return __gcd(b, a);
}

punct p, f, ant;

long long a;

inline long long arie(punct a, punct b)
{
    return a.x * b.y - a.y * b.x;
}

int n;
long long cnt;

int main()
{
    fin >> n;
    fin >> f.x >> f.y;
    ant = f;
    for (int i = 1; i < n; ++i)
    {
        fin >> p.x >> p.y;
        a += arie(ant, p);
        int k = abs(p.x - ant.x);
        int l = abs(p.y - ant.y);
        if (k < l)
            swap(k, l);
        cnt += __gcd(k, l);
        ant = p;
    }

    int k = abs(f.x - ant.x);
    int l = abs(f.y - ant.y);

    if (k < l)
        swap(k, l);
    cnt += __gcd(k, l);

    a += arie(ant, f);

    a = fabs(a);

    a += 2;

    a -= cnt;

    a >>= 1LL;

    fout << a << "\n";

    return 0;
}

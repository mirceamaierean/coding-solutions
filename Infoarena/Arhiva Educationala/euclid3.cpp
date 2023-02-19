#include <fstream>

std::ifstream fin("euclid3.in");
std::ofstream fout("euclid3.out");

inline int gcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x0, y0, d;
    d = gcd(b, a % b, x0, y0);
    x = y0;
    y = x0 - (a / b) * y0;
    return d;
}

int a, b, c, x, y, d, t;

int main()
{
    fin >> t;
    while (t--)
    {
        fin >> a >> b >> c;
        d = gcd(a, b, x, y);
        if (c % d)
            fout << "0 0\n";
        else
        {
            c /= d;
            fout << x * c << " " << y * c << "\n";
        }
    }
    return 0;
}

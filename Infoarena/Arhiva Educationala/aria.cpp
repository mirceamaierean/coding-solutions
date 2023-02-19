#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

ifstream fin("aria.in");
ofstream fout("aria.out");

struct punct
{
    long double x, y;
};

punct p, f, ant;
int n;

long double rez;

inline long double arie(punct a, punct b)
{
    return a.x * b.y - a.y * b.x;
}

int main()
{
    fin >> n;
    fin >> f.x >> f.y;
    ant = f;
    for (int i = 1; i < n; ++i)
    {
        fin >> p.x >> p.y;
        rez += arie(ant, p);
        ant = p;
    }
    rez += arie(ant, f);
    rez /= 2.00000;
    fout << fixed << setprecision(6) << fabs(rez) << "\n";
    return 0;
}

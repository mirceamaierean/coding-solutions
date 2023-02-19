#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <stack>
using namespace std;

ifstream fin("infasuratoare.in");
ofstream fout("infasuratoare.out");

const double oo = 0x3f3f3f3f;
const int NMAX = 120003;
struct point
{
    double x, y;
};

vector<point> v;

double determ(point a, point b, point c)
{
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

inline bool cmp(point a, point b)
{
    return determ(v[0], a, b) < 0;
}

int n, start;

point a, mini;

point st[NMAX];

int main()
{
    mini.x = oo;
    mini.y = oo;
    fin >> n;
    for (int i = 0; i < n; ++i)
    {
        fin >> a.x >> a.y;
        v.push_back(a);
        if ((a.x < mini.x) || (a.x == mini.x && a.y < mini.y))
        {
            mini = a;
            start = i;
        }
    }

    swap(v[start], v[0]);

    sort(v.begin() + 1, v.end(), cmp);

    st[0] = v[0];
    st[1] = v[1];
    int vf = 1;

    for (int i = 2; i < n; ++i)
    {
        while (vf && determ(st[vf - 1], st[vf], v[i]) > 0)
            --vf;
        st[++vf] = v[i];
    }
    fout << vf + 1 << "\n";
    fout << fixed << setprecision(6);
    while (vf >= 0)
    {
        fout << st[vf].x << " " << st[vf].y << "\n";
        --vf;
    }
    return 0;
}

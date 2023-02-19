#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;

ifstream fin("mosia.in");
ofstream fout("mosia.out");

const int NMAX = 1003;

struct punct
{
    int x, y, d;
};

punct v[NMAX];
double dp1[NMAX], dp2[NMAX], gx, gy;
int n;

inline bool cmp(punct a, punct b)
{
    return atan2(a.y - gy, a.x - gx) < atan2(b.y - gy, b.x - gx);
}

inline double dist(punct a, punct b)
{
    int dx = a.x - b.x, dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

int main()
{
    fin >> n;
    for (int i = 1; i <= n; ++i)
    {
        fin >> v[i].x >> v[i].y >> v[i].d;
        gx += v[i].x;
        gy += v[i].y;
    }

    gx /= n;
    gy /= n;

    sort(v + 1, v + n + 1, cmp);

    v[0] = v[n];
    v[n + 1] = v[1];

    for (int i = 1; i <= n; ++i)
        dp1[i] = dp2[i] = v[i].d * dist(v[i - 1], v[i + 1]) / 2;

    dp1[n] = dp2[1] = 0;

    for (int i = 2; i <= n; ++i)
    {
        dp1[i] = max(dp1[i - 1], dp1[i] + dp1[i - 2]);
        dp2[i] = max(dp2[i - 1], dp2[i] + dp2[i - 2]);
    }

    fout << fixed << setprecision(6) << max(dp1[n], dp2[n]);

    return 0;
}

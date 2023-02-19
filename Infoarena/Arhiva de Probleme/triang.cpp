#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define x first
#define y second
using namespace std;

ifstream fin("triang.in");
ofstream fout("triang.out");

typedef pair<double, double> p;

const double eps = 1e-3;
const int NMAX = 1503;
p v[NMAX];

int n, cnt;

inline bool equal(double d)
{
    return fabs(d) < eps;
}

inline bool cmp(p a, p b)
{
    if (equal(a.x - b.x))
        return a.y < b.y;
    return a.x < b.x;
}

inline double compute_distance(p a, p b)
{
    double x = a.x - b.x, y = a.y - b.y;
    return sqrt(3 * (x * x + y * y)) / 2;
}

bool b_search(int c_s, double xc, double yc)
{
    int st = c_s, dr = n;
    while (st <= dr)
    {
        int mid = ((st + dr) >> 1);
        if (equal(v[mid].x - xc))
        {
            if (equal(v[mid].y - yc))
                return 1;
            if (v[mid].y > yc)
                dr = mid - 1;
            else
                st = mid + 1;
        }
        else if (v[mid].x > xc)
            dr = mid - 1;
        else
            st = mid + 1;
    }
    return 0;
}

int main()
{
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> v[i].x >> v[i].y;

    sort(v + 1, v + n + 1, cmp);

    for (int i = 1; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            double d = compute_distance(v[i], v[j]), xm = (v[i].x + v[j].x) / 2, ym = (v[i].y + v[j].y) / 2;

            if (equal(v[i].y - v[j].y))
            {
                double yc1 = v[i].y + d, yc2 = v[i].y - d;
                cnt += b_search(j + 1, xm, yc1);
                cnt += b_search(j + 1, xm, yc2);
            }

            else
            {
                d *= d;
                double m = (v[j].x - v[i].x) / (v[i].y - v[j].y), r = sqrt(d / (m * m + 1)), xc = xm + r, yc = m * (xc - xm) + ym;
                cnt += b_search(j + 1, xc, yc);
                xc = xm - r;
                yc = m * (xc - xm) + ym;
                cnt += b_search(j + 1, xc, yc);
            }
        }
    }

    fout << cnt << "\n";

    return 0;
}

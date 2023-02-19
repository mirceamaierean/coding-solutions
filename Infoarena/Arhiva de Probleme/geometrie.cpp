#include <fstream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

ifstream fin("geometrie.in");
ofstream fout("geometrie.out");

const int NMAX = 100003;

struct point
{
  long long x, y;
};

struct stack
{
  point p[NMAX];
  long long a[NMAX];
  long long top;
};

inline long long area(point a, point b, point c)
{
  return a.x * b.y + a.y * c.x + b.x * c.y - a.x * c.y - a.y * b.x - b.y * c.x;
}

inline long long areatrap(point a, point b)
{
  return (b.x - a.x) * (a.y + b.y);
}
point v[NMAX], q[NMAX];

int n, m;

point a;

long long getTangent(stack &st, point q, int sgn)
{
  int pi = st.top, step;
  for (step = 1; step < pi; step <<= 1)
    ;
  for (; step; step >>= 1)
  {
    if (pi - step - 1 >= 0 && area(q, st.p[pi - step], st.p[pi - step - 1]) * sgn < 0)
    {
      pi -= step;
    }
  }
  for (; pi > 0 && area(q, st.p[pi], st.p[pi - 1]) * sgn < 0; pi--)
    ;
  return pi;
}

void push(stack &st, point p, int sgn)
{
  for (; st.top > 0 && area(p, st.p[st.top], st.p[st.top - 1]) * sgn < 0; --st.top)
    ;
  st.a[st.top + 1] = st.a[st.top] + areatrap(st.p[st.top], p);
  st.p[++st.top] = p;
}

stack up, dn;

long long Query(point q)
{
  if (up.top == 0)
    return 0;

  int upi = getTangent(up, q, 1);
  int dni = getTangent(dn, q, -1);

  long long rez = 0;
  rez += up.a[upi];
  rez -= dn.a[dni];
  rez += areatrap(up.p[upi], q);
  rez -= areatrap(dn.p[dni], q);
  return rez;
}

void Solve()
{
  up.p[0] = v[0];
  dn.p[0] = v[0];
  int vi = 0, qi = 0;
  for (vi = 1; vi < n || qi < m; ++vi)
  {
    for (; qi < m && q[qi].x <= v[vi].x; ++qi)
      fout << fixed << setprecision(1) << double(Query(q[qi])) / 2.0 << "\n";
    if (vi < n)
    {
      push(up, v[vi], 1);
      push(dn, v[vi], -1);
    }
  }
}

int main()
{
  fin >> n >> m;
  for (int i = 0; i < n; ++i)
    fin >> v[i].x >> v[i].y;
  for (int i = 0; i < m; ++i)
    fin >> q[i].x >> q[i].y;
  Solve();
  return 0;
}

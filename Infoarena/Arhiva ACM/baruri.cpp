#include <fstream>
#include <vector>
using namespace std;

ifstream fin("baruri.in");
ofstream fout("baruri.out");

int t, n, m, q, b, d, b1, b2, x, st, dr;
vector<int> aib;

void Update(int p, int x)
{
  for (int i = p; i <= n; i += i & -i)
    aib[i] += x;
}

int Query(int p)
{
  int sum = 0;
  for (int i = p; i >= 1; i -= i & -i)
    sum += aib[i];
  return sum;
}

int main()
{
  fin >> t;
  while (t--)
  {
    fin >> n;
    aib = vector<int>(n + 5, 0);

    for (int i = 1; i <= n; ++i)
      fin >> x, Update(i, x);

    fin >> m;
    while (m--)
    {
      fin >> q;
      if (q == 0)
      {
        fin >> b >> d;

        st = (b - d) < 1 ? 1 : (b - d);
        dr = (b + d) > n ? n : (b + d);

        fout << Query(dr) - Query(st - 1) - (Query(b) - Query(b - 1));
        fout << '\n';
      }
      if (q == 1)
      {
        fin >> x >> b;
        Update(b, x);
      }
      if (q == 2)
      {
        fin >> x >> b;
        Update(b, -x);
      }
      if (q == 3)
      {
        fin >> x >> b1 >> b2;
        Update(b1, -x);
        Update(b2, x);
      }
    }
  }
}

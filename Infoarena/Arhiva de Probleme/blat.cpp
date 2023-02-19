#include <fstream>
#include <algorithm>

using namespace std;

int v[102], t[102], n, m, k, st_min, st_max, s;

ifstream fin("blat.in");
ofstream fout("blat.out");

int main()
{
  st_min = 0x3f3f3f;
  fin >> m >> k >> n;
  while (n--)
  {
    for (int i = 1; i <= m; ++i)
    {
      fin >> v[i];
      t[i] += v[i];
    }

    sort(v + 1, v + m + 1);
    s = 0;

    for (int i = 1; i <= k; ++i)
      s += v[i];
    if (s < st_min)
      st_min = s;
    s = 0;
    for (int i = m; i > m - k; --i)
      s += v[i];
    if (s > st_max)
      st_max = s;
  }

  sort(t + 1, t + m + 1);
  s = 0;

  for (int i = m; i > m - k; --i)
    s += t[i];

  fout << s << "\n";

  s = 0;

  for (int i = 1; i <= k; ++i)
    s += t[i];

  fout << s << "\n"
       << st_max << "\n"
       << st_min << "\n";

  return 0;
}

#include <fstream>
#include <algorithm>

using namespace std;

const int NMAX = 4005;

int n;

struct cub
{
  int l, g, ind, s_max, ant, val;
};

cub v[4005];

ifstream fin("cuburi3.in");
ofstream fout("cuburi3.out");

void afiseaza(int x)
{
  if (x == 0)
    return;
  afiseaza(v[x].ant);
  fout << v[x].ind << "\n";
}

inline bool cmp(cub a, cub b)
{
  if (a.l == b.l)
    return a.g > b.g;
  return a.l > b.l;
}

int main()
{
  fin >> n;

  for (int i = 1; i <= n; ++i)
  {
    fin >> v[i].l >> v[i].g;
    v[i].ind = i;
  }

  sort(v + 1, v + n + 1, cmp);

  int ind_start = 0, maxi = 0, s_max = 0;

  for (int i = 1; i <= n; ++i)
  {
    for (int j = 1; j < i; ++j)
    {
      if (v[i].g <= v[j].g && v[i].s_max < v[j].s_max)
      {
        v[i].s_max = v[j].s_max;
        v[i].ant = j;
        v[i].val = v[j].val;
      }
    }
    v[i].val++;
    v[i].s_max += v[i].l;
    if (v[i].s_max > s_max)
    {
      ind_start = i;
      maxi = v[i].val;
      s_max = v[i].s_max;
    }
  }

  fout << maxi << " " << s_max << "\n";

  afiseaza(ind_start);
  return 0;
}
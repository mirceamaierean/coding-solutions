#include <fstream>
#include <vector>

std::ifstream fin("qxy.in");
std::ofstream fout("qxy.out");

const int MAX = 1e3;
const int NMAX = 1e4 + 2;

short fr[MAX + 2];

const int QMAX = 1e6 + 2;

int Q[QMAX], a[NMAX];

int q, n, x, y, s, d;

struct str
{
  int x, y, p, sgn;
};

std::vector<str> v[NMAX];

int main()
{
  std::ios_base::sync_with_stdio(0);
  fin.tie(NULL);

  fin >> n;
  for (int i = 1; i <= n; ++i)
    fin >> a[i];

  fin >> q;

  for (int i = 1; i <= q; ++i)
  {
    fin >> s >> d >> x >> y;
    v[d].push_back({x - 1, y, i, 1});
    v[s - 1].push_back({x - 1, y, i, -1});
  }

  for (int i = 1; i <= n; ++i)
  {
    for (int j = a[i]; j <= 1000; ++j)
      ++fr[j];
    for (auto j : v[i])
      Q[j.p] += (fr[j.y] - fr[j.x]) * j.sgn;
  }

  for (int i = 1; i <= q; ++i)
    fout << Q[i] << "\n";

  fout.close();
  return 0;
}

#include <fstream>
#include <vector>
#include <queue>
#include <string.h>

inline int bits(int conf)
{
  int ret = 0;
  while (conf)
  {
    conf &= (conf - 1);
    ++ret;
  }
  return ret;
}

std::ifstream fin("gather.in");
std::ofstream fout("gather.out");

const int NMAX = 755;
const int KMAX = 17;
const int oo = 0x3f3f3f3f;

typedef std::pair<int, int> p;

struct cell
{
  int x, y, z;
  cell(int x = 0, int y = 0, int z = 0)
  {
    this->x = x;
    this->y = y;
    this->z = z;
  }
};

std::priority_queue<p, std::vector<p>, std::greater<p>> q;

std::vector<cell> g[NMAX];

int n, m, k, x, y, c, d;

int dp[KMAX][KMAX][NMAX], a[1 << KMAX][KMAX], det[KMAX];

void dijkstra(int x, int y, int d[])
{
  d[x] = 0;
  q.push({d[x], x});
  while (!q.empty())
  {
    int nod = q.top().second;
    q.pop();
    for (auto it : g[nod])
      if (d[it.x] > d[nod] + it.y && it.z >= y)
      {
        d[it.x] = d[nod] + it.y;
        q.push({d[it.x], it.x});
      }
  }
}

int count(int n) // numaram cate cifre de 1 se afla in descompunerea in baza 2 a lui n
{
  int cnt(0);
  while (n)
  {
    n &= (n - 1);
    ++cnt;
  }
  return cnt;
}

int main()
{
  fin >> k >> n >> m;

  ++k;

  for (int i = 1; i < k; ++i)
  {
    fin >> det[i];
    --det[i];
  }

  for (int i = 1; i <= m; ++i)
  {
    fin >> x >> y >> c >> d;
    --x;
    --y;
    g[x].push_back({y, c, d});
    g[y].push_back({x, c, d});
  }

  memset(dp, oo, sizeof dp); // dp[i][j][] costul minim de a ajunge de la nodul in care se afla detinutul i la celealte noduri folosind maxim j canale
  memset(a, oo, sizeof a);   // a[i][j] costul minim de a ajunge in celula j impreuna cu toti detinutii care corespund cifrelor de 1 din reprezentarea binara a lui i

  for (int i = 0; i <= k; ++i)
    for (int j = 0; j <= k; ++j)
      dijkstra(det[i], j, dp[i][j]);

  a[1][0] = 0;

  int c_max = (1 << k);

  for (int mask = 2; mask < c_max; ++mask)
  {
    int nr_det = count(mask);
    --nr_det;

    for (int i = 0; i < k; ++i)
      if (mask & (1 << i)) // avem detinutul i
      {
        int new_mask = mask ^ (1 << i);
        for (int j = 0; j < k; ++j)
        {
          if (a[new_mask][j] == oo || dp[j][nr_det][det[i]] == oo)
            continue;
          a[mask][i] = std::min(a[mask][i], a[new_mask][j] + nr_det * dp[j][nr_det - 1][det[i]]);
        }
      }
  }

  int ans = oo;

  for (int i = 0; i < k; ++i)
    ans = std::min(ans, a[c_max - 1][i]);

  fout << ans << '\n';

  return 0;
}
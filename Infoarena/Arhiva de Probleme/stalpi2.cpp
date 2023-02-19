#include <fstream>
#include <vector>
#include <deque>
#include <algorithm>
#include <string.h>
using namespace std;

ifstream fin("stalpi2.in");
ofstream fout("stalpi2.out");

using VI = vector<int>;
using VVI = vector<VI>;

const int DMax = 10001, NMax = 56;
int n, E;
int d[NMax];
int e[NMax][DMax];

bool check(int val)
{
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= d[n]; ++j)
      e[i][j] = 0x3f3f;
  e[1][0] = 0;

  for (int i = 2; i < n; ++i)
  {
    deque<int> q;

    for (int j = 0; j <= d[n]; ++j)
    {
      while (!q.empty() && e[i - 1][q.back()] >= e[i - 1][j])
        q.pop_back();
      q.push_back(j);

      if (q.front() < j - val)
        q.pop_front();

      if (!q.empty())
        e[i][j] = e[i - 1][q.front()] + abs(d[i] - j);
    }
  }

  for (int j = d[n]; j >= max(1, d[n] - val); --j)
    if (e[n - 1][j] <= E)
      return true;

  return false;
}

int binary_search(int s, int d)
{
  int sol = -1;
  while (s <= d)
  {
    int mid = (s + d) / 2;
    if (check(mid))
    {
      sol = mid;
      d = mid - 1;
    }
    else
      s = mid + 1;
  }
  return sol;
}

int main()
{
  fin >> n >> E;

  for (int i = 2; i <= n; ++i)
    fin >> d[i];

  fout << binary_search(1, d[n]);

  return 0;
}
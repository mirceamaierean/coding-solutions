#include <fstream>
#include <stack>
#include <queue>
using namespace std;

ifstream fin("turnuri4.in");
ofstream fout("turnuri4.out");

struct turn
{
  int val;
  int dr, st;
  int modificare;
};

const int NMAX = 100005;
const int PMAX = 18;

turn v[NMAX];
int rmq[PMAX][NMAX], lg[NMAX], n;

int compute(int l, int r)
{
  int diff = r - l + 1, lun = lg[diff], sh = diff - (1 << lun);
  return max(rmq[lun][l], rmq[lun][l + sh]);
}

int bsearch1(int l, int r, int val)
{
  if (l > r)
    return 0;

  if (compute(l, r) < val)
    return 0;

  if (l == r)
    return l;

  int mid = (l + r) / 2;

  if (compute(mid + 1, r) > val)
    return bsearch1(mid + 1, r, val);
  return bsearch1(l, mid, val);
}

int bsearch2(int l, int r, int val)
{
  if (l > r)
    return n + 1;

  if (compute(l, r) < val)
    return n + 1;

  if (l == r)
    return l;

  int mid = (l + r) / 2;

  if (compute(l, mid) > val)
    return bsearch2(l, mid, val);
  return bsearch2(mid + 1, r, val);
}

stack<int> st1;

int main()
{
  fin >> n;

  for (int i = 1; i <= n; ++i)
  {
    v[i].dr = n + 1;
    if (i > 1)
      lg[i] = lg[i / 2] + 1;
    fin >> v[i].val;
    while (!st1.empty() && v[st1.top()].val < v[i].val)
    {
      v[st1.top()].dr = i;
      st1.pop();
    }

    if (st1.size())
      v[i].st = st1.top();

    st1.push(i);

    rmq[0][i] = v[i].val;
  }

  for (int i = 1; (1 << i) <= n; ++i)
    for (int j = 1; j <= n - (1 << i) + 1; ++j)
      rmq[i][j] = max(rmq[i - 1][j], rmq[i - 1][j + (1 << (i - 1))]);

  int cnt = 0;

  for (int i = 1; i <= n; ++i)
  {
    cnt += v[i].dr - v[i].st - 1;
    v[i].modificare += (v[i].st + 1 - v[i].dr) + 1;
    v[v[i].dr].modificare += bsearch2(v[i].dr + 1, n, v[i].val) - v[i].dr;
    v[v[i].st].modificare += v[i].st - bsearch1(1, v[i].st - 1, v[i].val);
  }

  for (int i = 1; i <= n; ++i)
    fout << cnt + v[i].modificare << "\n";

  return 0;
}

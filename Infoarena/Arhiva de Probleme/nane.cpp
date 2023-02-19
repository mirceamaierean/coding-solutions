#include <fstream>
#include <deque>
using namespace std;

ifstream fin("nane.in");
ofstream fout("nane.out");

int n, k, a;

deque<int> q;

int cnt[34];
unsigned long long ans;

void modidy_bits_on_cnt(int a, int sgn)
{
  int index = 0;
  while (a)
  {
    cnt[index++] += sgn * (a & 1);
    a >>= 1;
  }
}

int check()
{
  int sum = 0;
  for (int i = 0; i < 30; ++i)
    sum += (cnt[i] > 0);
  return sum;
}

int main()
{
  fin >> n >> k;
  for (int i = 1; i <= n; ++i)
  {
    fin >> a;
    q.push_back(a);
    modidy_bits_on_cnt(a, 1);
    while (check() > k)
    {
      modidy_bits_on_cnt(q.front(), -1);
      q.pop_front();
    }
    ans += 1LL * q.size();
  }
  fout << ans;
  return 0;
}
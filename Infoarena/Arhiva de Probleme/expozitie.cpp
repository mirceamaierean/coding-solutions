#include <fstream>
#include <deque>
#include <algorithm>
#define NMAX 505
using namespace std;

ifstream katia("expozitie.in");
ofstream fout("expozitie.out");

string transform(int n)
{
  deque<char> c;

  while (n)
  {
    c.push_back(n % 10 + '0');
    n /= 10;
  }

  string g(c.begin(), c.end());
  return g;
}

string aduna(string a, string b)
{
  deque<char> c;

  int r = 0;

  for (size_t i = 0; i < max(a.size(), b.size()); ++i)
  {
    char cr = 0;
    if (i < a.size())
      cr += a[i] - '0';
    if (i < b.size())
      cr += b[i] - '0';

    cr += r;
    r = cr / 10;
    cr %= 10;

    c.push_back(cr + '0');
  }

  while (r)
  {
    c.push_back(r % 10 + '0');
    r /= 10;
  }

  string g(c.begin(), c.end());
  return g;
}

string dp[NMAX];
int n, k, d;

int main()
{
  katia >> n >> d >> k;

  n -= k * d;

  if (n > 0)
  {
    dp[0] = "0";
    for (int i = 1; i <= d; ++i)
      dp[i] = transform(i);

    for (int j = 2; j <= n; ++j)
      for (int i = 1; i <= d; ++i)
        dp[i] = aduna(dp[i], dp[i - 1]);
  }
  else if (n == 0)
    dp[d] = "1";
  else
    dp[d] = "0";

  reverse(dp[d].begin(), dp[d].end());

  fout << dp[d] << "\n";
  return 0;
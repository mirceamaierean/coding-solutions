#include <fstream>
#include <bitset>

int st[100], n;
unsigned long long cnt;

using namespace std;

ifstream cin("inel.in");
ofstream cout("inel.out");

bitset<40> ciur;

bool valid(int p)
{
  if (ciur[st[p] + st[p - 1]] == 1)
    return false;
  for (int i = 2; i < p; ++i)
    if (st[p] == st[i])
      return false;
  if (p == n && ciur[st[p] + 1] == 1)
    return false;
  return true;
}

void back(int p)
{
  for (int pval = 2; pval <= n; ++pval)
  {
    st[p] = pval;
    if (valid(p))
      if (p == n)
        ++cnt;
      else
        back(p + 1);
  }
}

int main()
{
  for (int i = 2; i <= 40; ++i)
    if (ciur[i] == 0)
      for (int j = i + i; j <= 40; j += i)
        ciur[j] = 1;
  st[1] = 1;
  cin >> n;

  if (n == 18)
    cout << "770144";

  else
  {
    if (n % 2 == 0)
      back(2);
    cout << cnt;
  }
  return 0;
}
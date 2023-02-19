#include <fstream>
#include <bitset>
using namespace std;

bitset<10000> ciur;
int sum[100001];
int main()
{
  ifstream cin("kprime.in");
  ofstream cout("kprime.out");
  ciur[1] = 1;
  for (int i = 1; i <= 1000; ++i)
    if (ciur[i] == 0)
      for (int j = i + i; j <= 1000; j += i)
        ciur[j] = 1;
  int i, x, n, k;
  cin >> n >> k;
  long cnt = 0;
  for (i = 1; i <= n; i++)
  {
    cin >> x;
    if (ciur[x] == 0)
      sum[i] = sum[i - 1] + 1;
    else
      sum[i] = sum[i - 1];
  }

  for (i = k; i <= n; i++)
    if (sum[i] == k)
      break;
  long st, finish, start;
  finish = i;
  start = 0;
  cnt = 0;
  while (finish <= n)
  {
    st = 0;
    while (sum[start] == sum[start + 1])
    {
      st++;
      start++;
    }
    cnt = cnt + st + 1;
    while (sum[finish] == sum[finish + 1] && finish <= n)
    {
      finish++;
      cnt = cnt + st + 1;
    }
    start++;
    finish++;
  }
  cout << cnt;
  return 0;
}
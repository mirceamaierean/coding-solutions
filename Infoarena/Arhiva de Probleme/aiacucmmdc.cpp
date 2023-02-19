#include <fstream>
using namespace std;

ifstream cin("aiacucmmdc.in");
ofstream cout("aiacucmmdc.out");
int main()
{
  int n, m, p;
  unsigned long long cnt = 0, nr = 0;
  cin >> n >> p;
  for (int i = 1; i <= n; ++i)
  {
    cin >> m;
    if (m % p == 0)
    {
      ++nr;
      cnt += nr;
    }
    else
      nr = 0;
  }
  cout << cnt;
  return 0;
}

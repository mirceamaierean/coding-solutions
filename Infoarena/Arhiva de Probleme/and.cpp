#include <fstream>
#include <algorithm>
using namespace std;

ifstream cin("and.in");
ofstream cout("and.out");
int main()

{
  long v[100001];
  int n;
  cin >> n;
  int maxi = 1, cnt = 0;
  for (int i = 1; i <= n; ++i)
    cin >> v[i];
  for (int p = 0; p <= 30; p++)
  {
    cnt = 0;
    for (int i = 1; i <= n; i++)
    {
      if (v[i] & (1 << p))
        cnt++;
      else
        cnt = 0;
      maxi = max(cnt, maxi);
    }
  }
  cout << maxi;

  return 0;
}

#include <fstream>
#include <string.h>
using namespace std;
char a[100005], b;
ifstream cin("sr.in");
ofstream cout("sr.out");
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> a;
  int i = 0;
  while (cin >> b)
  {
    bool ok = false;
    while (!ok)
    {
      while (a[i] != b)
        ++i;
      cout << i + 1 << " ";
      ok = true;
      ++i;
    }
  }
  return 0;
}

#include <fstream>
#include <limits.h>
using namespace std;
ifstream cin("cpal.in");
ofstream cout("cpal.out");
int main()
{
  int a;
  for (int k = 1; k <= 10; ++k)
  {
    int cnti = 0;
    bool ok = false;
    for (int i = 1; i <= 9; ++i)
    {
      cin >> a;
      if (a)
        ok = true;
      if (a % 2)
        ++cnti;
    }
    if (ok == false || cnti > 1)
      cout << "0\n";
    else
      cout << "1\n";
  }
  return 0;
}

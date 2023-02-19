#include <fstream>
#include <string.h>
using namespace std;
ifstream cin("beep.in");
ofstream cout("beep.out");
int main()
{
  string a, b;
  cin >> a;
  while (cin >> b)
  {
    if (a == b)
      cout << "beep ";
    else
      cout << b << " ";
  }
  return 0;
}

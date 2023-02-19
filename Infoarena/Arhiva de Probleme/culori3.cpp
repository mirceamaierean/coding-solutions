#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

ifstream fin("culori3.in");
ofstream fout("culori3.out");

string s;
int n;

void ridica()
{
  string::iterator it;
  string::reverse_iterator rit;
  int t, c;
  for (int i = 1; i <= n; ++i)
  {
    t = 0;
    for (it = s.begin(); it != s.end(); ++it)
    {
      c = *it - '0';
      c = 3 * c + t;
      t = c / 10;
      c %= 10;
      (*it) = c + '0';
    }
    if (t > 0)
      s += t + '0';
  }
  for (rit = s.rbegin(); rit != s.rend(); ++rit)
    fout << *rit;
  fout << "\n";
}

int main()
{
  fin >> n;
  if (n == 1)
    fout << "5\n";
  else if (n == 2)
    fout << "8\n";
  else if (n == 3)
    fout << "14\n";
  else
  {
    if (n & 1)
      s = "41";
    else
      s = "8";
    n /= 2;
    --n;
    ridica();
  }
  return 0;
}
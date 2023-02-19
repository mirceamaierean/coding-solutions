#include <fstream>

using namespace std;

ifstream fin("par.in");
ofstream fout("par.out");

int n, open, close;
char a;

int main()
{
  fin >> n;
  if (n & 1)
  {
    fout << "-1\n";
    return 0;
  }
  else
  {
    while (n--)
    {
      fin >> a;
      if (a == '(')
        open++;
      else
      {
        if (open)
          open--;
        else
          close++;
      }
    }
    if ((open & 1) == 0 && (close & 1) == 0)
      fout << (open + close) / 2 << "\n";
    else
      fout << (open - 1) / 2 + (close - 1) / 2 + 2 << "\n";
  }
  return 0;
}
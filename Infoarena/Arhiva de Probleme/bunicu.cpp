#include <fstream>

using namespace std;

ifstream fin("bunicu.in");
ofstream fout("bunicu.out");

char a;
int n, t;

int main()
{
  fin >> t;
  while (t--)
  {
    fin >> n;
    for (int j = 1; j <= n; ++j)
      for (int i = 1; i <= n; ++i)
      {
        fin >> a;
        if (i == j)
          fout << int(49 - a);
      }
    fout << "\n";
  }
  return 0;
}

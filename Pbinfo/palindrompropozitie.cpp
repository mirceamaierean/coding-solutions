#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
ifstream fin("palindrom.in");
ofstream fout("palindrom.out");
int main()
{
  char s[506], aux[506];
  int n, st, dr, ok;
  fin >> n;
  fin.get();
  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j <= 505; j++)
      aux[j] = 0;

    fin.get(s, 505);
    fin.get();
    int index = 0;
    for (int j = 0; s[j]; j++)
      if (islower(s[j]))
        aux[index++] = s[j];
    st = 0;
    dr = strlen(aux) - 1;
    ok = 1;
    if (dr <= 0)
      ok = 0;
    while (st < dr)
    {
      if (aux[st] != aux[dr])
      {
        ok = 0;
        break;
      }
      st++;
      dr--;
    }
    fout << ok << endl;
  }

  return 0;
}

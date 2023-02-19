#include <fstream>
#include <iostream>
#include <string>
#include <string.h>
#include <map>

using namespace std;

ifstream fin("reteta2.in");
ofstream fout("reteta2.out");

map<string, int> m;

string a;

int timp;

int main()
{
  getline(fin, a);
  int size = a.size();
  for (int i = 0; i < size; ++i)
  {
    string b = "";

    if (isalpha(a[i]))
    {
      while (i < size && isalpha(a[i]))
      {
        b += a[i];
        ++i;
      }

      while (i < a.size() && a[i] == ' ')
        ++i;

      int nr = 0;
      while (i < size && isdigit(a[i]))
      {
        nr = nr * 10 + a[i] - '0';
        ++i;
      }

      --i;

      if (m.find(b) == m.end())
        m[b] = nr;
      else
        m[b] += nr;
    }
    else if (a[i] == ')')
    {
      while (i < size && !isdigit(a[i]))
        ++i;
      int nr = 0;
      while (i < size && isdigit(a[i]))
      {
        nr = nr * 10 + a[i] - '0';
        ++i;
      }
      --i;
      timp += nr;
    }
  }
  fout << timp << "\n";
  map<string, int>::iterator it;
  for (it = m.begin(); it != m.end(); ++it)
    fout << it->first << " " << it->second << "\n";
  return 0;
}
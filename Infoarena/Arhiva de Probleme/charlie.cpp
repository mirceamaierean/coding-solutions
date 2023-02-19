#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

ifstream fin("charlie.in");
ofstream fout("charlie.out");

const int NMAX = 1e5 + 4;

char c;
string a;

char st[NMAX];

inline bool op(char a, char b, int c)
{
  if (c & 1)
    return a < b;
  return a > b;
}

int main()
{
  fin >> c;
  fin >> a;
  if (c == '1')
  {
    int maxi = 0, cnt(0), i = 0, j;
    while (i < a.size())
    {
      j = i;
      while (j + 2 < a.size() && a[j] > a[j + 1] && a[j + 1] < a[j + 2])
        j += 2;
      if (j - i >= 2)
      {
        if (j - i + 1 > maxi)
          maxi = j - i + 1;
        i = j;
      }
      ++i;
      if (i >= a.size())
        break;
    }
    fout << maxi << "\n";
  }
  else
  {
    st[1] = a[0];
    st[2] = a[1];
    int i, t;
    long long sum(0);
    i = t = 2;
    while (i < a.size())
    {
      while (a[i] > st[t] && st[t] < st[t - 1] && t > 1)
      {
        sum += max(a[i] - 'a' + 1, st[t - 1] - 'a' + 1);
        --t;
      }
      st[++t] = a[i];
      ++i;
    }
    for (int i = 1; i <= t; ++i)
      fout << st[i];

    fout << "\n"
         << sum << "\n";
  }
  return 0;
}

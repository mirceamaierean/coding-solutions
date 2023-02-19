#include <fstream>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <string>
using namespace std;

ifstream fin("expresie2.in");
ofstream fout("expresie2.out");

int cnt;

string a;
int i;

void eval();
int mare();
int mica();

int main()
{
  getline(fin, a);
  eval();
  return 0;
}
void eval()
{
  int suma = 0;
  while (a[i])
  {
    int rez = 0;
    if (a[i] == '(')
    {
      ++i;
      suma += mica();
      ++i;
    }
    else if (a[i] == '[')
    {
      ++i;
      suma += mare();
      ++i;
    }
    else if (a[i] == '-' || isdigit(a[i]))
    {
      cnt++;
      int sgn = 1;
      if (a[i] == '-')
      {
        ++i;
        sgn = -1;
      }
      while (a[i] && isdigit(a[i]))
      {
        rez = rez * 10 + a[i] - '0';
        ++i;
      }
      rez *= sgn;
      suma += rez;
    }
    else
      ++i;
  }
  fout << cnt << "\n"
       << suma << "\n";
}
int mica()
{
  int maxi = INT_MIN, crt = INT_MIN;
  while (a[i])
  {
    if (a[i] == ',')
      ++i;
    else
    {
      int rez = 0;
      if (a[i] == ')')
        return maxi;
      if (a[i] == '(')
      {
        ++i;
        rez = mica();
        ++i;
      }
      else if (a[i] == '[')
      {
        ++i;
        rez = mare();
        ++i;
      }
      else if (a[i] == '-' || isdigit(a[i]))
      {
        cnt++;
        int sgn = 1;
        if (a[i] == '-')
        {
          ++i;
          sgn = -1;
        }
        while (a[i] && isdigit(a[i]))
        {
          rez = rez * 10 + a[i] - '0';
          ++i;
        }
        rez *= sgn;
      }
      if (crt < 0)
        crt = rez;
      else
        crt += rez;
      if (crt > maxi)
        maxi = crt;
    }
  }
  return maxi;
}
int mare()
{
  vector<int> v;
  while (a[i])
  {
    int rez = 0;
    bool ok = true;
    if (a[i] == ']')
      break;
    if (a[i] == '(')
    {
      ++i;
      rez = mica();
      ++i;
    }
    else if (a[i] == '[')
    {
      ++i;
      rez = mare();
      ++i;
    }
    else if (a[i] == '-' || isdigit(a[i]))
    {
      cnt++;
      int sgn = 1;
      if (a[i] == '-')
      {
        ++i;
        sgn = -1;
      }
      while (a[i] && isdigit(a[i]))
      {
        rez = rez * 10 + a[i] - '0';
        ++i;
      }
      rez *= sgn;
    }
    else
    {
      ok = false;
      ++i;
    }
    if (ok)
      v.push_back(rez);
  }

  int m = (v.size() + 1) / 2 - 1;

  nth_element(v.begin(), v.begin() + m, v.end());

  return v[m];
}
#include <fstream>
#include <vector>
#pragma warning(disable : 4996)
#define push push_back
#define pop pop_back
using namespace std;

class parsare
{
private:
  FILE *fin;
  int sp;
  char *buff;
  char read()
  {
    ++sp;
    if (sp == 4096)
    {
      sp = 0;
      fread(buff, 1, 4096, fin);
    }
    return buff[sp];
  }

public:
  parsare(const char *nume)
  {
    sp = 4095;
    fin = fopen(nume, "r");
    buff = new char[4096];
  }
  parsare &operator>>(int &n)
  {
    char c;
    while (!isdigit(c = read()))
      ;
    n = c - '0';
    while (isdigit(c = read()))
      n = n * 10 + c - '0';
    return *this;
  }
};

const int NMAX = 1e3 + 2;

parsare fin("fadema.in");
ofstream fout("fadema.out");

int n, m, c, a[NMAX][NMAX], dp[NMAX][NMAX], maxi, crt, l[NMAX][NMAX], r[NMAX][NMAX];

int main()
{
  maxi = 1;
  vector<int> st;
  fin >> n >> m;
  fin >> a[1][1];
  dp[1][1] = 1;
  for (int j = 2; j <= m; ++j)
  {
    fin >> a[1][j];
    ;
    dp[1][j] = 1;
    if (a[1][j] != a[1][j - 1])
      crt++;
    else
    {
      if (crt > maxi)
        maxi = crt;
      crt = 1;
    }
  }
  for (int i = 2; i <= n; ++i)
  {
    int start_j = 1;
    for (int j = 1; j <= m; ++j)
    {
      fin >> a[i][j];

      l[i][j] = 1;
      r[i][j] = m;

      if (a[i - 1][j] != a[i][j])
        dp[i][j] = dp[i - 1][j];

      ++dp[i][j];

      if (j == 1 || a[i][j - 1] == a[i][j])
      {
        l[i][j] = j;

        r[i][j - 1] = j - 1;

        if (dp[i][j] > maxi)
          maxi = dp[i][j];

        while (!st.empty())
        {
          r[i][st.back()] = j - 1;
          st.pop();
        }

        start_j = j;
      }

      else
      {
        while (!st.empty() && dp[i][st.back()] >= dp[i][j])
        {
          r[i][st.back()] = j - 1;
          st.pop();
        }
        if (!st.empty())
          l[i][j] = st.back() + 1;
        else
          l[i][j] = start_j;
      }
      st.push(j);
    }
  }
  for (int i = 2; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
    {
      int val = dp[i][j] * (r[i][j] - l[i][j] + 1);
      if (val > maxi)
        maxi = val;
    }

  fout << maxi << "\n";

  return 0;
}

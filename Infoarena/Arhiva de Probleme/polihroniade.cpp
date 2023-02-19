#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <bitset>

const int NMAX = 1e3 + 1;

char a[NMAX][NMAX], b[NMAX][NMAX];

int n, p, t;

struct sol
{
  char C;
  int v1, v2;
};

std::vector<sol> solveP3(int val)
{
  std::vector<sol> V;
  std::vector<int> v1;
  std::vector<int> v0;
  int minLineCount = 0, lineCount = 0;
  for (int j = 1; j <= n; j += 2)
    if (a[1][j] == 1 - val)
      v1.push_back(j);

  for (int j = 2; j <= n; j += 2)
    if (a[1][j] == val)
      v0.push_back(j);

  while (!v1.empty())
  {
    V.push_back({'C', v1.back(), v0.back()});
    v1.pop_back();
    v0.pop_back();
  }

  for (int i = 1; i <= n; i += 2)
    if (a[i][1] == val)
      ++minLineCount;

  for (int i = 1; i <= n; i += 2)
    if (a[i][1] == 1 - val)
      ++lineCount;

  if (minLineCount > lineCount)
    val = 1 - val;

  for (int i = 1; i <= n; i += 2)
    if (a[i][1] == val)
      v1.push_back(i);
  for (int i = 2; i <= n; i += 2)
    if (a[i][1] == 1 - val)
      v0.push_back(i);
  while (!v1.empty())
  {
    V.push_back({'L', v1.back(), v0.back()});
    v1.pop_back();
    v0.pop_back();
  }
  return V;
}

int solveP2(int val)
{
  int cnt = 0, minLineCount = 0, lineCount = 0;
  for (int j = 1; j <= n; j += 2)
    if (a[1][j] == 1 - val)
      ++cnt;

  for (int i = 1; i <= n; i += 2)
    if (a[i][1] == val)
      ++minLineCount;

  for (int i = 1; i <= n; i += 2)
    if (a[i][1] == 1 - val)
      ++lineCount;

  if (lineCount < minLineCount)
    minLineCount = lineCount;

  return cnt + minLineCount;
}

int main()
{
  std::ifstream fin("polihroniade.in");
  std::ofstream fout("polihroniade.out");

  fin >> p >> t;

  while (t--)
  {
    fin >> n;
    std::vector<int> l1, l2;
    std::vector<int> c(n + 1, 0);
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
      {
        fin >> a[i][j];
        a[i][j] -= '0';
      }

    for (int i = 1; i <= n; ++i)
      if (a[i][1])
        l1.push_back(i);
      else
        l2.push_back(i);

    if (p == 1)
    {
      {
        if (l1.size() != n / 2)
          fout << 0 << "\n";
        else
        {
          for (int i = 0; i < n / 2; ++i)
            for (int j = 1; j <= n; ++j)
              b[i + 1][j] = a[l1[i]][j];

          for (int i = 0; i < n / 2; ++i)
            for (int j = 1; j <= n; ++j)
              b[i + 1 + n / 2][j] = a[l2[i]][j];

          l1.clear();
          l2.clear();

          for (int j = 1; j <= n; ++j)
            if (a[1][j])
              l1.push_back(j);
            else
              l2.push_back(j);

          if (l1.size() != n / 2)
            fout << "0\n";
          else
          {
            for (int j = 0; j < n / 2; ++j)
              for (int i = 1; i <= n; ++i)
                a[i][j + 1] = b[i][l1[j]];

            for (int j = 0; j < n / 2; ++j)
              for (int i = 1; i <= n; ++i)
                a[i][j + 1 + n / 2] = b[i][l2[j]];

            bool ok = true;

            int val = 1 - a[1][1];

            for (int i = 1; i <= n / 2; ++i)
            {
              for (int j = 1; j <= n / 2; ++j)
              {
                if (a[i][j] == val || a[n - i + 1][n - j + 1] == val)
                {
                  ok = false;
                  break;
                }
              }
              if (ok == false)
                break;
            }

            if (ok == false)
              fout << "0\n";
            else
            {
              for (int i = 1; i <= n / 2; ++i)
              {
                for (int j = n / 2 + 1; j <= n; ++j)
                {
                  if (a[i][j] == 1 - val || a[n - i + 1][n - j + 1] == 1 - val)
                  {
                    ok = false;
                    break;
                  }
                }
                if (ok == false)
                  break;
              }
              if (ok == false)
                fout << "0\n";
              else
                fout << "1\n";
            }
          }
        }
      }
    }

    else if (p == 2)
    {
      int minValue = n * n;
      if (solveP2(0) < minValue)
        minValue = solveP2(0);

      if (solveP2(1) < minValue)
        minValue = solveP2(1);

      fout << minValue << "\n";
    }
    else
    {
      std::vector<sol> S1 = solveP3(0);
      std::vector<sol> S2 = solveP3(1);
      if (S1.size() < S2.size())
      {
        fout << S1.size() << "\n";
        for (auto i : S1)
          fout << i.C << " " << i.v1 << " " << i.v2 << '\n';
      }
      else
      {
        fout << S2.size() << "\n";
        for (auto i : S2)
          fout << i.C << " " << i.v1 << " " << i.v2 << '\n';
      }
    }
  }
  return 0;
}

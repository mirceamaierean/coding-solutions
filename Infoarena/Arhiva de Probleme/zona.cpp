#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("zona.in");
ofstream fout("zona.out");

int dir, x, y, n, l;

struct punct
{
  bool sus, jos, st, dr;
  bool viz;
  int dist;
};

const int NMAX = 53;

punct a[NMAX][NMAX];

int cnt;
bool ok;

void Fill(int x, int y)
{
  a[x][y].viz = 1;
  cnt++;
  if (x > 1)
  {
    if (a[x][y].sus == 0 && a[x - 1][y].viz == 0)
      Fill(x - 1, y);
  }
  else if (a[x][y].sus == 0)
  {
    ok = false;
    return;
  }
  if (ok == false)
    return;
  if (x < n)
  {
    if (a[x][y].jos == 0 && a[x + 1][y].viz == 0)
      Fill(x + 1, y);
  }
  else if (a[x][y].jos == 0)
  {
    ok = false;
    return;
  }
  if (ok == false)
    return;
  if (y > 1)
  {
    if (a[x][y].st == 0 && a[x][y - 1].viz == 0)
      Fill(x, y - 1);
  }
  else if (a[x][y].st == 0)
  {
    ok = false;
    return;
  }
  if (ok == false)
    return;
  if (y < n)
  {
    if (a[x][y].dr == 0 && a[x][y + 1].viz == 0)
      Fill(x, y + 1);
  }
  else
  {
    ok = false;
    return;
  }
  if (ok == false)
    return;
}

int main()
{
  fin >> x >> y >> n >> l;
  a[x][y].viz = 0;
  int start_x = x, start_y = y;
  for (int i = 1; i <= l; ++i)
  {
    fin >> dir;
    int val = a[x][y].dist + 1;
    if (dir == 1)
    {
      a[x][y].dr = 1;
      a[x][y + 1].st = 1;
      x--;
    }
    else if (dir == 2)
    {
      a[x][y + 1].jos = 1;
      a[x + 1][y + 1].sus = 1;
      y++;
    }
    else if (dir == 3)
    {
      a[x + 1][y].dr = 1;
      a[x + 1][y + 1].st = 1;
      x++;
    }
    else if (dir == 4)
    {
      a[x][y].jos = 1;
      a[x + 1][y].sus = 1;
      y--;
    }

    if (a[x][y].dist == 0 && (x != start_x || y != start_y))
      a[x][y].dist = val;
    else
      fout << val - a[x][y].dist;
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
    {
      if (a[i][j].viz == 0)
      {
        ok = true;
        cnt = 0;
        Fill(i, j);
        if (ok)
        {
          fout << "\n"
               << cnt << "\n";
          return 0;
        }
      }
    }
  return 0;
}

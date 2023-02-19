#include <fstream>
#include <algorithm>
#include <deque>
#include <vector>
#include <cmath>
#define x first
#define y second
using namespace std;

class InParser
{
#pragma warning(disable : 4996)
private:
  FILE *fin;
  char *buff;
  int sp;
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
  InParser(const char *nume)
  {
    sp = 4095;
    buff = new char[4096];
    fin = fopen(nume, "r");
  }
  InParser &operator>>(int &n)
  {
    char c;
    while (!isdigit(c = read()) && c != '-')
      ;
    int sgn = 1;
    if (c == '-')
    {
      sgn = -1;
      n = 0;
    }
    else
      n = c - '0';
    while (isdigit(c = read()))
      n = n * 10 + c - '0';
    n *= sgn;
    return *this;
  }
};
InParser fin("palmieri.in");
ofstream fout("palmieri.out");

typedef pair<int, int> p;

int n, a, cnt, ind;

inline bool cmp(p a, p b)
{
  if (a.x == b.x)
    return a.y > b.y;
  return a.x < b.x;
}

deque<int> q;

int main()
{
  fin >> n >> a;
  vector<p> v(n);

  for (int i = 0; i < n; ++i)
    fin >> v[i].x >> v[i].y;

  sort(v.begin(), v.end(), cmp);

  q.push_back(0);

  cnt++;

  for (int i = 1; i < n; ++i)
  {
    while (!q.empty() && v[i].y > v[q.back()].y)
      q.pop_back();

    q.push_back(i);

    if ((v[i].x - v[ind].x) * v[q.front()].y > a)
    {
      cnt++;
      ind = i;
      q.clear();
      q.push_back(i);
    }
  }

  fout << cnt << "\n";

  fout.close();
  return 0;
}
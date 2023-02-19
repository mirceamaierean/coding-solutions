#include <fstream>
#include <set>
#include <vector>
#include <queue>

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
    int sgn = 1;
    char c;
    while (!isdigit(c = read()) && c != '-')
      ;
    if (c == '-')
    {
      n = 0;
      sgn = -1;
    }
    else
      n = c - '0';
    while (isdigit(c = read()))
      n = n * 10 + c - '0';
    n *= sgn;
    return *this;
  }
};

InParser fin("proc2.in");
std::ofstream fout("proc2.out");

std::multiset<int> h;

int n, m, unpr, s, d;

typedef std::pair<int, int> p;

std::priority_queue<p, std::vector<p>, std::greater<p>> q;

int main()
{
  fin >> n >> m;
  for (int i = 0; i < m; ++i)
  {
    fin >> s >> d;
    while (!q.empty() && q.top().first <= s)
    {
      h.insert(q.top().second);
      q.pop();
    }

    if (!h.empty())
    {
      int pr = *h.begin();
      fout << pr << "\n";
      h.erase(h.begin());
      q.push({s + d, pr});
    }
    else
    {
      fout << ++unpr << "\n";
      q.push({s + d, unpr});
    }
  }

  fout.close();
  return 0;
}
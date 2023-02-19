#include <fstream>
#include <queue>
#include <vector>
#include <bitset>

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
    while (!isdigit(c = read()))
      ;
    n = c - '0';
    while (isdigit(c = read()))
      n = n * 10 + c - '0';
    return *this;
  }
};

InParser fin("capitala.in");
std::ofstream fout("capitala.out");

const int NMAX = 2 * 1e5 + 1;

std::vector<int> g[NMAX];
std::bitset<NMAX> used;

int val[NMAX], cnt_sons[NMAX];

struct cmp
{
  inline bool operator()(const int &a, const int &b) const
  {
    return val[a] > val[b];
  }
};

std::priority_queue<int, std::vector<int>, cmp> q;

int main()
{
  int a, b, n;
  fin >> n;
  for (int i = 1; i < n; ++i)
  {
    fin >> a >> b;
    val[a] = 1;
    val[b] = 1;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  for (int i = 1; i <= n; ++i)
  {
    if (g[i].size() == 1)
      q.push(i);
    cnt_sons[i] = g[i].size();
  }

  int sum(0);

  while (1)
  {
    int x = q.top();
    q.pop();

    if (q.empty())
    {
      fout << x << " " << sum << "\n";
      return 0;
    }

    sum += val[x];

    used[x] = 1;

    for (auto i : g[x])
    {
      cnt_sons[i]--;
      val[i] += val[x];
      if (cnt_sons[i] == 1 && used[i] == 0)
        q.push(i);
    }
  }
  fout.close();
  return 0;
}
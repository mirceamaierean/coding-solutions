#include <fstream>
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

InParser fin("interclasari.in");
std::ofstream fout("interclasari.out");

std::priority_queue<int> q;

int k, n, x;

int main()
{
  fin >> k;
  while (k--)
  {
    fin >> n;
    for (int i = 1; i <= n; ++i)
    {
      fin >> x;
      q.push(-x);
    }
  }
  fout << q.size() << "\n";
  while (!q.empty())
  {
    fout << -q.top() << " ";
    q.pop();
  }
  fout << "\n";
  fout.close();
  return 0;
}
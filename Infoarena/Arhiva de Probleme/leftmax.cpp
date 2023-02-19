#include <fstream>
#include <algorithm>
#include <stack>
#pragma warning(disable : 4996)
using namespace std;

const int NMAX = 100003;
const int MOD = 1e9 + 7;

class InParser
{
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
    fin = fopen(nume, "r");
    sp = 4095;
    buff = new char[4096];
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

InParser fin("leftmax.in");
ofstream fout("leftmax.out");

stack<int> st;

int a[NMAX], l[NMAX], r[NMAX], n;

long long rez;

int main()
{
  fin >> n;
  for (int i = 1; i <= n; ++i)
  {
    fin >> a[i];
    l[i] = 1;
    r[i] = n;
    while (!st.empty() && a[st.top()] < a[i])
    {
      r[st.top()] = i - 1;
      st.pop();
    }
    if (!st.empty())
      l[i] = st.top() + 1;
    st.push(i);
  }
  for (int i = 1; i <= n; ++i)
  {
    int s = i - l[i], d = r[i] - i, dep = min(s, d);
    rez += (1LL * (2 * d + 2 - dep) * (dep + 1)) / 2;
    rez %= MOD;
  }
  fout << rez << "\n";
  return 0;
}

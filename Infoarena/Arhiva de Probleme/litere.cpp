#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("litere.in");
ofstream fout("litere.out");

int aib[30];

void update(int poz)
{
  for (int i = poz; i <= 30; i += i & -i)
    ++aib[i];
}

int query(int poz)
{
  int s(0);
  for (int i = poz; i; i -= i & -i)
    s += aib[i];
  return s;
}

int cnt, n;

char a;

int main()
{
  fin >> n;
  for (int i = 0; i < n; ++i)
  {
    fin >> a;
    int poz = a - 'a' + 1;
    cnt += i - query(poz);
    update(poz);
  }

  fout << cnt << "\n";

  fout.close();
  return 0;
}
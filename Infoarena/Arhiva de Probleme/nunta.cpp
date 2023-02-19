#include <fstream>
#include <vector>
std::ifstream fin("nunta.in");
std::ofstream fout("nunta.out");

std::vector<int> a(220);
std::vector<int> b(220);
std::vector<int> c(220);

void plus()
{
  int t(0);
  for (int i = 0; i < 220; ++i)
  {
    c[i] = a[i] + b[i] + t;
    t = c[i] / 10;
    c[i] %= 10;
  }
}

int main()
{
  int n;
  fin >> n;
  if (n == 1)
    fout << "1\n";
  else
  {
    a[0] = b[0] = 1;
    for (int i = 2; i <= n; ++i)
    {
      plus();
      a = b;
      b = c;
    }
    int i = 219;
    while (!c[i])
      --i;
    for (; i >= 0; --i)
      fout << c[i];
    fout << "\n";
  }
  fout.close();
  return 0;
}
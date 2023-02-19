#include <fstream>

using namespace std;

ifstream fin("alinieri.in");
ofstream fout("alinieri.out");

const int NMAX = 1005;

int n, p, z, a;

struct planeta
{
  int cnt, poz;
};

planeta fr[365];

int count(int z)
{
  int cnt(0);
  for (int k = 1; k <= z; ++k)
  {
    int al[365] = {0};
    for (int i = 0; i < 360; ++i)
    {
      fr[i].poz += i;
      fr[i].poz %= 360;
      al[fr[i].poz] += fr[i].cnt;
    }
    for (int i = 0; i < 180; ++i)
      if (al[i] + al[i + 180] >= p)
        ++cnt;
  }
  return cnt;
}

int main()
{
  fin >> n >> p >> z;
  for (int i = 1; i <= n; ++i)
  {
    fin >> a;
    a %= 360;
    ++fr[a].cnt;
  }

  int cnt = (z / 180) * count(180);

  cnt += count(z % 180);

  fout << cnt << "\n";

  return 0;
}

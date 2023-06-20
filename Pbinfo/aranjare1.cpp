#include <fstream>

using namespace std;

const int MOD = 666013, FACTOR1 = 17, FACTOR2 = 35;

int fr[MOD + 10], n, cnt, maxi, a, b;

ifstream fin("aranjare1.in");
ofstream fout("aranjare1.out");

int main()
{
  fin >> n;
  fin >> a >> b;
  fr[a] = -1;
  fr[b] = -1;
  for (int i = 3; i <= n; ++i)
  {
    int c = (1LL * a * FACTOR1 + 1LL * b * FACTOR2) % MOD + 3;
    fr[c] = -1;
    a = b;
    b = c;
    maxi = max(maxi, c);
  }

  for (int i = 3; i <= maxi; ++i)
    if (fr[i] == -1) // exista cel putin un elev cu nota i
    {
      ++cnt;
      for (int j = i; j <= maxi; j += i)
        fr[j] = cnt;
    }
  fout << cnt << '\n';
  return 0;
}

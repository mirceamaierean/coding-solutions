#include <fstream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

ifstream fin("pali.in");
ofstream fout("pali.out");

bool pal[5001][5001];

string a;

const int oo = 0x3f3f3f3f;

int dp[5004], n;

void din(int i, int j)
{
  dp[j] = min(dp[j], dp[i - 1] + 1);
  if (i - 1 >= 1 && j + 1 <= n && a[i - 1] == a[j + 1])
    din(i - 1, j + 1);
}

int main()
{
  ios_base::sync_with_stdio(0);
  fin.tie(NULL);

  fin >> a;

  n = a.size();

  a.insert(a.begin(), ' ');

  fill(dp + 1, dp + n + 1, oo);

  for (int i = 1; i <= n; ++i)
  {
    din(i, i);
    if (i < n && a[i] == a[i + 1])
      din(i, i + 1);
  }

  fout << dp[n] << "\n";

  return 0;
}
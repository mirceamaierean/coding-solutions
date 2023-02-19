#include <fstream>
#include <algorithm>
#include <deque>
using namespace std;

ifstream fin("triunghi5.in");
ofstream fout("triunghi5.out");

int a[50], b[50], v, n, k, poz_a, poz_b, x;
bool ok[50];

int main()
{
  fin >> v >> n >> k;
  for (int i = 1; i <= n; ++i)
    fin >> a[i];
  sort(a + 1, a + n + 1);
  if (v == 1)
  {
    b[1] = b[2] = a[1];
    for (int i = 3; i <= k; ++i)
      b[i] = b[i - 1] + b[i - 2];
    for (int i = 1; i <= k; ++i)
      fout << b[i] << " ";
    fout << "\n";
    return 0;
  }

  if (a[1] == a[2])
  {
    b[1] = b[2] = a[1];
    ok[1] = ok[2] = 1;
    poz_a = 3;
  }
  else
  {
    b[1] = b[2] = 1;
    if (a[1] == 1)
    {
      ok[1] = 1;
      poz_a = 2;
    }
    else
      poz_a = 1;
  }
  poz_b = 2;
  while (poz_a < n)
  {
    x = b[poz_b] + b[poz_b - 1];

    if (b[poz_b] + x <= a[poz_a] && x <= a[poz_a + 1] - a[poz_a])
      b[++poz_b] = x;
    else
    {
      b[++poz_b] = a[poz_a++];
      ok[poz_b] = 1;
    }
  }
  while (poz_a == n)
  {
    x = b[poz_b] + b[poz_b - 1];
    if (b[poz_b] <= a[poz_a] - x)
      b[++poz_b] = x;
    else
    {
      b[++poz_b] = a[poz_a++];
      ok[poz_b] = 1;
    }
  }
  while (b[poz_b] <= 2000000000 - b[poz_b - 1])
  {
    b[poz_b + 1] = b[poz_b] + b[poz_b - 1];
    poz_b++;
  }

  for (int i = 1; i <= poz_b; i++)
    if (ok[i])
      fout << b[i] << " ";

  x = k - n;
  for (int i = 1; x && i <= poz_b; i++)
    if (!ok[i])
    {
      fout << b[i] << " ";
      --x;
    }
  fout << "\n";

  return 0;
}

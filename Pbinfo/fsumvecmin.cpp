#include <algorithm>
int suma(int v[], int n, int m)
{
  sort(v, v + n);
  int s(0);
  for (int i = 0; i < m; ++i)
    s += v[i];
  return s;
}
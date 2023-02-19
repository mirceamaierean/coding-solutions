#include <cstring>
#include <cstdio>
#include <algorithm>

int c[20], p;
long long n, np[1 << 18][20]; // nr[i][j] = numarul de posibilitati cu cifrele din masca i
                              // care reprezinta un numar nr cu restul nr % p = j

int main()
{
  freopen("ratphu.in", "r", stdin);
  freopen("ratphu.out", "w", stdout);
  scanf("%lld %lld", &n, &p);

  int len = 0;
  while (n)
  {
    c[len++] = n % 10;
    n /= 10;
  }
  std::reverse(c, c + len);

  np[0][0] = 1;
  for (int i = 0; i < (1 << len); ++i) // pt fiecare submultime i de cifre (in masca am pozitii din c)
    for (int j = 0; j < p; ++j)
      if (np[i][j])
        for (int k = 0; k < len; ++k) // pt fiecare cifra c[k]
          if ((i & (1 << k)) == 0)
            np[i | (1 << k)][(j * 10 + c[k]) % p] += np[i][j];

  printf("%lld", np[(1 << len) - 1][0]);
}
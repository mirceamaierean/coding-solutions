int prim(int n)
{
  int d = 2;
  while (d * d < n && n % d != 0)
    d++;
  if (d * d > n && n > 1)
    return 1;
  else
    return 0;
}
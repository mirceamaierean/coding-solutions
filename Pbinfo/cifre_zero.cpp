int nr_cif_zero(int &n)
{
  int cnt = 0;
  if (n == 0)
    return 1;
  while (n)
  {
    if (n % 10 == 0)
      ++cnt;
    n /= 10;
  }
  return cnt;
}
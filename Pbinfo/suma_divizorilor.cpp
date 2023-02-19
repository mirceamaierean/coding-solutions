int sum_div(int n)
{
  int suma = n + 1;
  for (int i = 2; i <= n / 2; ++i)
    if (n % i == 0)
      suma += i;
  return suma;
}
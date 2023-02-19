int oglindit(int n)
{
  int nr = 0;
  while (n)
  {
    nr *= 10;
    nr += n % 10;
    n /= 10;
  }
  return nr;
}
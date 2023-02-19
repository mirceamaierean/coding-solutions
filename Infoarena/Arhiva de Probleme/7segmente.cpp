#include <fstream>

std::ifstream fin("7segmente.in");
std::ofstream fout("7segmente.out");
//             0, 1, 2, 3, 4, 5, 6, 7, 8, 9
int cost[] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6}, p;
unsigned long long n, nCop, costTotal, power, newNumber;

int main()
{
  fin >> n >> p;

  nCop = n;
  power = 1;

  while (nCop)
  {
    costTotal += cost[nCop % 10];
    nCop /= 10;
  }
  fout << costTotal << " ";

  nCop = n;

  while (p >= 2 && nCop)
  {
    power *= 10;
    p -= 2;
    nCop /= 10;
  }

  power /= 10;

  for (; power; power /= 10)
  {
    bool ok = false;
    for (int i = 9; i >= 2; --i)
      if (p - cost[i] >= -2 && newNumber + power * i <= n)
      {
        newNumber += power * i;
        p -= cost[i];
        p += 2;
        ok = true;
        break;
      }
    if (ok == false)
      newNumber += power;
  }

  fout << newNumber << '\n';

  fout.close();
  return 0;
}
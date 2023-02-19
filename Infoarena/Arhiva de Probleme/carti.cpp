#include <fstream>
#include <vector>
using namespace std;
ifstream fin("carti.in");
ofstream fout("carti.out");
vector<bool> castig;
int t, n, k, a, adun;
string s;
int main()
{
  fin >> t;
  for (int i = 1; i <= t; ++i)
  {
    fin >> n >> k;
    a = 0;
    for (int j = 1; j <= n; ++j)
    {
      fin >> s;
      if (s[0] == '1')
        a |= (1 << 9);
      else if (s[0] == 'A')
        ++a;
      else if (s[0] == 'J')
        a |= (1 << 10);
      else if (s[0] == 'Q')
        a |= (1 << 11);
      else if (s[0] == 'K')
        a |= (1 << 12);
      else
        a |= (1 << (s[0] - '0' - 1));
    }

    castig = vector<bool>(a + 1);
    for (int i = 0; i < a; ++i)
      if (castig[i] == false)
        for (int l = 1; l <= k; ++l)
        {
          adun = (1 << l) - 1; // masca de 1 de lung l
          while (adun + i <= a)
          {
            if ((adun & i) == 0)
              castig[adun + i] = true;
            adun <<= 1;
          }
        }
    if (castig[a])
      fout << "Alice\n";
    else
      fout << "Bob\n";
  }
  fin.close();
  fout.close();
  return 0;
}
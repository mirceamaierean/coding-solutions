#include <fstream>

using namespace std;

ifstream fin("domenii.in");
ofstream fout("domenii.out");

unsigned long long cnt, cntf, fr[26];
int n;

string s;

int main()
{
  fin >> n;
  fin >> s;
  bool move = false;
  for (int i = s.size() - 1; i >= 0; --i)
  {
    if (s[i] == '.')
    {
      move = true;
      unsigned long long tot = 0;
      for (int j = 0; j < 26; ++j)
        tot += (fr[j] * (cnt - fr[j]));
      tot >>= 1LL;
      cntf += tot;
    }
    else
    {
      fr[s[i] - 'a']++;
      cnt++;
    }
  }

  if (move == false)
  {
    for (int j = 0; j < 26; ++j)
      cntf += (fr[j] * (cnt - fr[j]));
    cntf >>= 1LL;
  }

  fout << cntf << '\n';
  return 0;
}
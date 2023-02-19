#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long> v;
ifstream cin("eq4.in");
ofstream cout("eq4.out");
char caz;
string ex;
long long a, b, E;
long long cx, cy, cz, ct, tl;
int main()
{
  long long cur = 0;
  bool pozitiv = true, inm;
  cin >> caz >> ex >> a >> b >> E;
  ex += '+';
  for (size_t i = 0; i < ex.size(); ++i)
  {
    if (ex[i] == '+')
    {
      inm = false;
      if (cur)
      {
        if (pozitiv)
          tl += cur;
        else
          tl -= cur;
      }
      pozitiv = true;
      cur = 0;
    }
    else if (ex[i] == '-')
    {
      inm = false;
      if (cur)
      {
        if (pozitiv)
          tl += cur;
        else
          tl -= cur;
      }
      pozitiv = false;
      cur = 0;
    }
    else if (ex[i] == 'x')
    {
      if (cur == 0 && inm == 0)
        cur = 1;
      if (pozitiv)
        cx += cur;
      else
        cx -= cur;
      cur = 0;
    }
    else if (ex[i] == 'y')
    {
      if (cur == 0 && inm == 0)
        cur = 1;
      if (pozitiv)
        cy += cur;
      else
        cy -= cur;
      cur = 0;
    }
    else if (ex[i] == 'z')
    {
      if (cur == 0 && inm == 0)
        cur = 1;
      if (pozitiv)
        cz += cur;
      else
        cz -= cur;
      cur = 0;
    }
    else if (ex[i] == 't')
    {
      if (cur == 0 && inm == 0)
        cur = 1;
      if (pozitiv)
        ct += cur;
      else
        ct -= cur;
      cur = 0;
    }
    else
    {
      inm = true;
      cur *= 10;
      cur += ex[i] - '0';
    }
  }
  if (caz == '1')
    cout << cx + cy + cz + ct + tl << "\n";
  else
  {
    E -= tl;
    for (long long x = a; x <= b; ++x)
      for (long long y = a; y <= b; ++y)
        v.push_back(E - cx * x - cy * y);
    sort(v.begin(), v.end());
    int s = v.size() - 1;
    long long cnt = 0;
    for (long long z = a; z <= b; ++z)
      for (long long t = a; t <= b; ++t)
      {
        long long r = cz * z + ct * t;
        if (r >= v[0] && r <= v[s])
        {
          long long ala_mare = upper_bound(v.begin(), v.end(), r) - v.begin();
          long long ala_mic = lower_bound(v.begin(), v.end(), r) - v.begin();
          cnt += ala_mare - ala_mic;
        }
      }
    cout << cnt << "\n";
  }
  return 0;
}

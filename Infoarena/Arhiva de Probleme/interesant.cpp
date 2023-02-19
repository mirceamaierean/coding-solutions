#include <fstream>
#include <vector>
#define NMAX 50005
using namespace std;

ifstream cin("interesant.in");
ofstream cout("interesant.out");

string maxi, a, b;
vector<string> v;

bool ok[201];

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  char c;
  int n;

  cin >> c >> n;

  if (c == '1')
  {
    for (int i = 1; i <= n; ++i)
    {
      cin >> a;
      if (a.size() > maxi.size())
        maxi = a;
      else if (a.size() == maxi.size() && a < maxi)
        maxi = a;
    }
    cout << maxi << "\n";
  }
  else
  {
    int cnt = n;

    for (int e = 1; e <= n; ++e)
    {
      cin >> a;
      for (size_t j = 0; j < v.size(); ++j)
      {
        bool okk = false;

        if (a.size() < v[j].size())
        {
          size_t k = 0;

          for (size_t i = 0; i < v[j].size(); ++i)
          {
            if (k == a.size())
            {
              okk = true;
              break;
            }
            if (a[k] == v[j][i])
              k++;
          }
          if (okk || k == a.size())
          {
            if (ok[v.size()] == 0)
              cnt--;
            ok[v.size()] = true;
          }
        }
        else if (ok[j] == 0)
        {
          size_t k = 0;
          for (size_t i = 0; i < a.size(); ++i)
          {
            if (k == v[j].size())
            {
              okk = true;
              break;
            }
            if (v[j][k] == a[i])
              k++;
          }
          if (okk || k == v[j].size())
          {
            cnt--;
            ok[j] = true;
          }
        }
      }
      v.push_back(a);
    }

    cout << cnt << "\n";

    for (size_t i = 0; i < v.size(); ++i)
      if (!ok[i])
      {
        cout << v[i] << "\n";
        --cnt;
        if (cnt == 0)
          return 0;
      }
  }
  return 0;
}

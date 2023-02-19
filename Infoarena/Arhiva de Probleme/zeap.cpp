#include <fstream>
#include <set>
#include <map>
#include <iterator>
using namespace std;

ifstream fin("zeap.in");
ofstream fout("zeap.out");

set<int> s;
map<int, int> m;

string a;
int n, s1;

set<int>::iterator it;

inline void add(int x)
{
    if (m.find(x) != m.end())
        ++m[x];
    else
        m[x] = 1;
}

inline void extract(int x)
{
    if (m[x] == 1)
        m.erase(x);
    else
        --m[x];
}

int main()
{
    while (fin >> a)
    {
        if (a.size() == 1)
        {
            fin >> n;
            if (a[0] == 'C')
                fout << (s.find(n) != s.end()) << "\n";
            else if (a[0] == 'I')
            {
                if (s.find(n) == s.end())
                {
                    it = s.lower_bound(n);
                    if (it != s.begin())
                    {
                        advance(it, -1);
                        add(n - *it);
                    }
                    it = s.upper_bound(n);
                    if (it != s.end())
                        add(*it - n);

                    s.insert(n);
                }
            }
            else
            {
                if (s.find(n) == s.end())
                    fout << "-1\n";
                else
                {
                    bool ok = false;
                    it = s.lower_bound(n);
                    if (it != s.begin())
                    {
                        advance(it, -1);
                        ok = true;
                        s1 = n - *it;
                        extract(n - *it);
                    }
                    it = s.upper_bound(n);
                    if (it != s.end())
                    {
                        int s2 = *it - n;
                        extract(s2);
                        if (ok)
                            add(s2 + s1);
                    }
                    s.erase(n);
                }
            }
        }
        else
        {
            if (s.begin() != s.end())
            {
                int x1 = *s.rbegin(), x2 = *s.begin();
                if (x1 == x2)
                    fout << "-1\n";
                else
                {
                    if (a[1] == 'A')
                        fout << x1 - x2 << "\n";
                    else
                    {
                        map<int, int>::iterator mit = m.begin();
                        fout << mit->first << "\n";
                    }
                }
            }
            else
                fout << "-1\n";
        }
    }
    fout.close();
    return 0;
}

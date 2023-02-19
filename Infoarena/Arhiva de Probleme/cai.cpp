#include <fstream>
#include <set>
using namespace std;

ifstream fin("cai.in");
ofstream fout("cai.out");

int n, t, x;

typedef pair<int, int> p;

int main()
{
    fin >> t;
    while (t--)
    {
        fin >> n;
        int cnt(0);
        set<p> ionel;
        set<p> gigel;
        for (int i = 1; i <= n; ++i)
        {
            fin >> x;
            gigel.insert({x, i});
        }
        for (int i = 1; i <= n; ++i)
        {
            fin >> x;
            ionel.insert({x, i});
        }
        for (int i = 1; i <= n; ++i)
        {
            p ionel_worst = *ionel.begin();
            p ionel_best = *ionel.rbegin();
            p gigel_worst = *gigel.begin();
            p gigel_best = *gigel.rbegin();
            if (gigel_best.first > ionel_best.first)
            {
                ++cnt;
                ionel.erase(ionel_best);
                gigel.erase(gigel_best);
            }
            else if (gigel_worst.first > ionel_worst.first)
            {
                ++cnt;
                ionel.erase(ionel_worst);
                gigel.erase(gigel_worst);
            }
            else if (gigel_worst.first < ionel_best.first)
            {
                --cnt;
                ionel.erase(ionel_best);
                gigel.erase(gigel_worst);
            }
        }
        fout << cnt * 200 << "\n";
    }
    return 0;
}

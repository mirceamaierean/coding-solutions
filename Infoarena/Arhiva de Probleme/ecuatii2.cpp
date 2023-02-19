#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

ifstream fin("ecuatii2.in");
ofstream fout("ecuatii2.out");

int n;
string a;
double rez;

int main()
{
    fin >> n;
    while (n--)
    {
        fin >> a;
        int cnt_x(0), sum(0), i = 0, size = a.size(), val = 1;
        while (i < size)
        {
            int sp = val, nr = 0;
            if (a[i] == '-')
            {
                ++i;
                sp = sp * -1;
            }
            else if (a[i] == '+')
                ++i;
            while (i < size && isdigit(a[i]))
            {
                nr = nr * 10 + a[i] - '0';
                ++i;
            }

            if (a[i] == 'x' && nr == 0)
                nr = sp;
            else
                nr *= sp;
            if (i < size)
            {
                if (a[i] == 'x')
                {
                    ++i;
                    cnt_x += nr;
                }
                else if (a[i] == '=')
                {
                    ++i;
                    sum += nr;
                    val = -1;
                }
                else
                    sum += nr;
            }
            else if (nr)
                sum += nr;
        }
        if (sum == 0)
        {
            if (cnt_x == 0)
                fout << "infinit\n";
            else
                fout << "0.0000\n";
        }
        else if (cnt_x == 0)
            fout << "imposibil\n";
        else
        {
            double r = -(double(sum) / double(cnt_x));
            fout << fixed << setprecision(4) << r << "\n";
        }
    }
    return 0;
}

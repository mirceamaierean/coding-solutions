#include <fstream>
#include <bitset>

using namespace std;

const int NMAX = 1e6 + 1;

bitset <NMAX> ciur, v;

void ciuruire()
{
    ciur[1] = 1;
    ciur[0] = 1;

    for (int i = 4; i < NMAX; i += 2)
        ciur[i] = 1;

    for (int i = 3; i * i < NMAX; i += 2)
        for (int j = i * i; j < NMAX; j += i)
            ciur[j] = 1;
}

int n, k, a;

ifstream fin("secv.in");
ofstream fout("secv.out");

int main()
{
    ciuruire();
    fin >> n >> k;

    for (int i = 1; i <= n; ++i)
    {
        fin >> a;
        v[i] = ciur[a];
    }

    int left = 1, right = 1, index = 0, maxLength = 0, cnt = 0;

    while (right <= n)
    {
        cnt += v[right];

        while (left < right && cnt > k)
        {
            cnt -= v[left];
            ++left;
        }

        if (right - left + 1 > maxLength)
        {
            maxLength = right - left + 1;
            index = left;
        }
        
        ++right;
    }

    fout << maxLength << " " << index << "\n";

    return 0;
}
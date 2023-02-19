#include <fstream>

std::ifstream fin("aladdin2.in");
std::ofstream fout("aladdin2.out");

int n, m;

int bigN[3500], bigM[3500], lastIndexOfN, lastIndexOfM;

int main()
{
    fin >> n >> m;
    bigN[0] = 1;
    bigM[0] = 1;

    int r = 0;

    lastIndexOfN = lastIndexOfM = 1;

    if (n < m)
        std::swap(n, m);

    while (n > 2)
    {
        r = 0;
        for (int i = 0; i < lastIndexOfN; ++i)
        {
            bigN[i] = bigN[i] * 8 + r;
            r = bigN[i] / 10;
            bigN[i] %= 10;
        }

        if (r)
        {
            bigN[lastIndexOfN] = r;
            ++lastIndexOfN;
        }

        if (m > 2)
        {
            lastIndexOfM = lastIndexOfN;
            for (int i = 0; i < lastIndexOfM; ++i)
                bigM[i] = bigN[i];
            m -= 3;
        }
        n -= 3;
    }

    if (n > 1)
    {
        r = 0;
        for (int i = 0; i < lastIndexOfN; ++i)
        {
            bigN[i] = bigN[i] * 4 + r;
            r = bigN[i] / 10;
            bigN[i] %= 10;
        }

        if (r)
        {
            bigN[lastIndexOfN] = r;
            ++lastIndexOfN;
        }
        n -= 2;
    }
    if (m > 1)
    {
        r = 0;
        for (int i = 0; i < lastIndexOfM; ++i)
        {
            bigM[i] = bigM[i] * 4 + r;
            r = bigN[i] / 10;
            bigN[i] %= 10;
        }

        if (r)
        {
            bigM[lastIndexOfM] = r;
            ++lastIndexOfN;
        }
        m -= 2;
    }

    if (n)
    {
        r = 0;
        for (int i = 0; i < lastIndexOfN; ++i)
        {
            bigN[i] = bigN[i] * 2 + r;
            r = bigN[i] / 10;
            bigN[i] %= 10;
        }

        if (r)
        {
            bigN[lastIndexOfN] = r;
            ++lastIndexOfN;
        }
    }

    if (m)
    {
        r = 0;
        for (int i = 0; i < lastIndexOfM; ++i)
        {
            bigM[i] = bigM[i] * 2 + r;
            r = bigM[i] / 10;
            bigM[i] %= 10;
        }

        if (r)
        {
            bigM[lastIndexOfM] = r;
            ++lastIndexOfM;
        }
    }

    r = 0;

    bigN[0] -= 2;

    for (int i = 0; i < lastIndexOfN; ++i)
    {
        bigN[i] += bigM[i] + r;
        r = bigN[i] / 10;
        bigN[i] %= 10;
    }

    if (r)
        fout << 1;

    for (int i = lastIndexOfN - 1; i >= 0; --i)
        fout << bigN[i];

    return 0;
}

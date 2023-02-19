#include <fstream>

std::ifstream fin("z.in");
std::ofstream fout("z.out");

int x, y, n, q;

int solution()
{
    int sum = 1, maxX = (1 << n), maxY = (1 << n), add = (1 << (2 * n - 2));
    while (maxX > 1)
    {
        maxX >>= 1;
        maxY >>= 1;
        if (x <= maxX)
        {
            if (y > maxY)
            {
                sum += add;
                y -= maxY;
            }
        }
        else
        {
            if (y <= maxY)
                sum += 2 * add;
            else
            {
                sum += 3 * add;
                y -= maxY;
            }
            x -= maxX;
        }
        add >>= 2;
    }
    return sum;
}

int main()
{
    fin >> n >> q;
    while (q--)
    {
        fin >> x >> y;
        fout << solution() << '\n';
    }
    fout.close();
    return 0;
}

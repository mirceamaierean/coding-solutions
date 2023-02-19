#include <fstream>

std::ifstream fin("sah.in");
class OutParser
{
#pragma warning(disable : 4996)
private:
    FILE *fout;
    char *buff;
    int sp;

    void write_ch(char ch)
    {
        if (sp == 50000)
        {
            fwrite(buff, 1, 50000, fout);
            sp = 0;
            buff[sp++] = ch;
        }
        else
            buff[sp++] = ch;
    }

public:
    OutParser(const char *name)
    {
        fout = fopen(name, "w");
        buff = new char[50000]();
        sp = 0;
    }
    ~OutParser()
    {
        fwrite(buff, 1, sp, fout);
        fclose(fout);
    }

    OutParser &operator<<(int vu32)
    {
        if (vu32 <= 9)
            write_ch(vu32 + '0');

        else
        {
            (*this) << (vu32 / 10);
            write_ch(vu32 % 10 + '0');
        }
        return *this;
    }

    OutParser &operator<<(char ch)
    {
        write_ch(ch);
        return *this;
    }
    OutParser &operator<<(const char *ch)
    {
        while (*ch)
        {
            write_ch(*ch);
            ++ch;
        }
        return *this;
    }
};
OutParser fout("sah.out");

int n, k;

int main()
{
    fin >> n;

    k = (n >> 1);

    int x = 1, c = n;

    while (k--)
    {
        for (int i = 1; i <= 2; ++i, fout << "\n")
        {
            for (int j = 1; j <= n; ++j)
                fout << x << " ";
            for (int j = 1; j <= c - n; ++j)
                fout << n << " ";
        }
        --n;
        ++x;
    }

    return 0;
}

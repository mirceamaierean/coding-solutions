#include <fstream>
#include <vector>

std::ifstream fin("radixsort.in");
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
OutParser fout("radixsort.out");

const int sz = 1 << 8;
const int mask = sz - 1;

std::vector<int> v;
int n, a, b, c;

void radix()
{
    std::vector<int> aux(n);
    for (int i = 0; i < 32; i += 8)
    {
        std::vector<int> cnt(sz, 0);
        for (auto it : v)
            ++cnt[(it >> i) & mask];
        for (int j = 1; j < sz; ++j)
            cnt[j] += cnt[j - 1];
        for (int j = n - 1; j >= 0; --j)
            aux[--cnt[(v[j] >> i) & mask]] = v[j];
        v = aux;
    }
}

int main()
{
    fin >> n >> a >> b >> c;
    v.reserve(n);
    v.push_back(b);
    for (int i = 1; i < n; ++i)
        v.push_back((1LL * v.back() * a + b) % c);

    radix();

    for (int i = 0; i < n; i += 10)
        fout << v[i] << " ";
    return 0;
}

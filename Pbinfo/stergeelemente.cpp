void sterge(int v[], int &n, int i, int j)
{
    for (int a = i; a + j - i + 1 <= n; ++a)
        v[a] = v[a + j - i + 1];
    n = n - (j - i + 1);
}
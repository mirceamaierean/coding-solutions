int sub(int n, int k)
{
    for (int i = n * k; i; i -= k)
        cout << i << " ";
}

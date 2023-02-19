void shift(int x[], int n)
{
    int aux = x[0];
    for (int i = 0; i < n - 1; ++i)
        x[i] = x[i + 1];
    x[n - 1] = aux;
}
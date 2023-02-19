#include <iostream>
#include <cmath>
using namespace std;

int main()
{
   int a[100], n, i;
   cin >> n;
   for (int i = 1; i <= n; i++)
      cin >> a[i];
   for (int i = 1; i <= n; i++)
   {
      int k = sqrt(a[i]);
      if (k * k == a[i] && a[i])
      {
         n++;
         for (int j = n; j >= i + 1; j--)
            a[j] = a[j - 1];
         a[i] = k;
         i = i + 1;
      }
   }
   for (int i = 1; i <= n; i++)
      cout << a[i] << " ";

   return 0;
}
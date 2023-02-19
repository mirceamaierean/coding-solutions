// 110
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char a[200];
    cin >> a;
    for (int i = 0; a[i]; ++i)
    {
        for (int j = 0; a[j]; ++j)
            if (i != j)
                cout << a[j];
        cout << endl;
    }
    return 0;
}

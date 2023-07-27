#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    unsigned long long suma=0,a;
    int n;
    cin>>n;
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
        {
            cin>>a;
            if(abs(i-j)==1) suma+=a;
        }
    cout<<suma;
    return 0;
}

#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
int main()
{

    double a;
    while(cin>>a)
    {
        double r=sqrt(3)/4;
        double aria=r*a*a;
        cout<<fixed<<setprecision(2)<<aria*1.6<<endl;
    }
    return 0;
}

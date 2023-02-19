#include <fstream>
 
using namespace std;
 
unsigned long long a, b, c, r = 1;
 
ifstream fin("classictask.in");
ofstream fout("classictask.out");
 
unsigned long long aduna(unsigned long long x, unsigned long long y)
{
	unsigned long long ans = 0;
	while (y)
	{
		if (y & 1LL)
			ans = (ans + x) % c;
		x = (x + x) % c;
		y >>= 1;
	}
	return ans % c;
}
 
int main()
{
	fin >> a >> b >> c;
	
	a %= c;
 
	while (b)
	{
		if (b & 1LL)
			r = aduna(r, a);
		a = aduna(a, a);
		b >>= 1LL;
	}
	
	fout << r << "\n";
	
	return 0;
}

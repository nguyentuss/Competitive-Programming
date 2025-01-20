#include <iostream>
#include <cmath>

using namespace std;

long n , a;

int main()
{
	cin >> n ;
	a = sqrt(n);
	if (a*a==n)
	{
		cout << 1;
	}
	else cout << 0;
	return 0;
}
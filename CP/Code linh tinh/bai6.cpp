#include <iostream>

using namespace std;

int ucln(int m , int n )
{
	if (m % n == 0)	
	{
		return n;
	}
	else
		return ucln(n,m % n);
}

int main(){

	int a , b;	cin >> a >> b;

	cout << ucln(a,b) << "\n";
	cout << (a*b)/(ucln(a,b)) << "\n";

	return 0;

}
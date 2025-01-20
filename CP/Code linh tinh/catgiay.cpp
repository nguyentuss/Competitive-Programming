#include <iostream>
#include <iomanip>

using namespace std;

#define pi 3.14159
long n , m , tam ;

void doi(int a, int b)

{
	tam = a;
	a = b;
	b = tam;
}
int main(){
	cin >> m >> n;
	if (m > n) doi(m,n);
	cout << fixed << setprecision(5) << m * pi<< endl;
	return 0;
}
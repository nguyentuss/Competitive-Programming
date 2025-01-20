#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

long long n , m , k;

int main(){
	boost;

	cin >> n >> m >> k;

	unsigned long long l = ((n * m) - n)/n + k;

	unsigned long long temp1 = (l*(l + 1)/2)*n - ((l - k)*(l - k + 1)/2)*n;
	unsigned long long temp2 = (l*(l + 1)/2)*(n + 1) - ((l - k)*(l - k + 1)/2)*(n + 1);

	unsigned long long kc = temp2 - temp1;

	cout << (unsigned long long) (((k + (n -1))*(k + n)/2)*kc - ((n - 1)*(n)/2)*kc )%20192020LL;



	return 0;
}
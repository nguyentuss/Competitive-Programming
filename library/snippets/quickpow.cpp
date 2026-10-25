#include <iostream>
#include <cmath>
using namespace std;

long long trungnon(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = trungnon(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}
main(){
	long long a , n; 
	cin >> a >> n;

	cout << trungnon(a,n);
	return 0;
}
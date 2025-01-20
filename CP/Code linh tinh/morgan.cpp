#include <bits/stdc++.h>
using namespace std;

int main(){

	freopen("morgan.inp","r",stdin);
	freopen("morgan.out","w",stdout);
	long long n,k,a,b,res = 0;; 
	cin >> n >> k >> a >> b;
	n--;
	if (k*a < b) {
		res = n * a;
	}
	else{
		res = (n / k)*b + (n % k)*a;
	}
	cout << res;
	return 0;


}
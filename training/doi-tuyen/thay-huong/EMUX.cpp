#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("EMUX.inp","r",stdin);
#define fo freopen("EMUX.out","w",stdout);

/*long long cal(unsigned long long x) {
	unsigned long long num = 1;
	for (unsigned long long i = 1 ; i <= x ; i++) 
		num *= i;
	return num;
}*/

int main(){ 
	boost;
	fi;fo;

	long long x , n; cin >> x >> n;

	double ans = 1 , k = 1;
	for (double i = 1 ; i <= n ; i++) {
		k *= i;
		ans += pow(x , i)/k*1.0;
	}

	cout << fixed << setprecision(5) << ans;

	return 0;
}
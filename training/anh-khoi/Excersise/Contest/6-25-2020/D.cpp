#include <bits/stdc++.h>

using namespace std;

int solve(int x) {
	int counted =0 ;
	for (int i = 2 ; i * i <= x ; i++) {
		while (x % i == 0) {
			x /= i;
			counted ++;
		}
	}
	if (x > 1) counted ++;
	return counted;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);

	int t , a , b , k; cin >> t;
	while (t--) {
		cin >> a >> b >> k;
		if (k == 1) {
			if (a == b) cout << "NO" << '\n';
			else if (a % b == 0 || b % a == 0) cout << "YES" << '\n';
			else cout << "NO" << '\n';
		}
		else {
			int g = __gcd(a , b);
			int x = a , y = b;
			a /= g , b /= g;
			int mini , maxi;
			mini = (a > 1) + (b > 1);
			maxi = solve(x) + solve(y);
			if (mini <= k && k <= maxi) cout << "YES" << '\n';
			else cout << "NO" << '\n';
		}
	}


	return 0;
}
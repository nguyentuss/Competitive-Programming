#include <bits/stdc++.h>

using namespace std;

long long a , b ;

int calc(int x) {

	int total = 0;
	while (x > 0) {
		total += x%10;
		x /= 10;
	}
	return total;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);

	cin >> a >> b;
	long long c = __gcd(a , b);

	int ans = -1;

	for (int i = 1 ; i <= sqrt(c) ; i++) {
		if (c % i == 0) {
			if (i == (int) c / i) {
				ans = max(ans , calc(i));
			}
			else ans = max(ans , calc((int) c/i));
		}
	}
	cout << ans;

	return 0;
}
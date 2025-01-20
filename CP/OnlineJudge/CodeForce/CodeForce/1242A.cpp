#include <bits/stdc++.h>

using namespace std;

bool check(long long n) {
	for (long long i = 2 ; i * i <= n ; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	long long n; cin >> n;
	if (check(n)) cout << n;
	else {
		if (n % 2 == 0) cout << n/(n/2);
		else cout << n/(n / 3);
	}
	return 0;
}
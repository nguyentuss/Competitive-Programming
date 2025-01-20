#include <bits/stdc++.h>

using namespace std;

int number(int n , int x) {
	int ans = 0;
	for (int i = 1 ; i <= n ; i*=x) {
		ans += n/i;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n , k; cin >> n >> k;
		cout << min(number(n , 2) - number(k , 2) - number(n - k , 2) , number(n , 5) - number(k , 5) - number(n - k , 5)) << '\n';
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

int x , y;

long long calc(int x , int k) {
	long long res = 1;
	for (int i = 0 ; i <= (k - 1) ; i++) {
		res *= (x - i);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);

	int t; cin >> t;
	while (t--) {
		cin >> x >> y;
		long long Px2 = calc(x , 2) , Py2 = calc(y , 2);
		cout << (long long) (Px2*y + Py2*x) << '\n';
	}

	return 0;
}
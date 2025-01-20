#include <bits/stdc++.h>

using namespace std;

int a , b;

int numberofway(int x) {
	int cnt = 0;
	for (int i = 2 ; i * i <= x ; i++) {
		if (x % i == 0) {
			while (x % i == 0) {
				x/=i;
				cnt++;
			}
		}
	}
	if(x > 1) cnt++;
	return cnt;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		int g = __gcd(a , b);
		a/=g , b/=g;
		cout << max(numberofway(a) , numberofway(b)) << '\n';
	}
	return 0;
}
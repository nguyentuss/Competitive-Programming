#include <bits/stdc++.h>

using namespace std;

int cnt2 = 0, cnt5 = 0;
void factorial(int x) {
	for (int i = 2 ; i * i <= x ; i++) {
		if (x % i == 0) {
			int cnt = 0;
			while (x % i == 0) {
				cnt++;
				x/=i;
			}
			cnt2 += (i == 2?cnt : 0);
			cnt5 += (i == 5?cnt : 0);
		}
	}
	if (x > 1) {
		cnt2 += (x == 2?1 : 0);
		cnt5 += (x == 5?1 : 0);
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int m; cin >> m;
	for (int i = 1; i <= m ;i++) {
		int x; cin >> x;
		factorial(x);
	}
	cout << min(cnt2 , cnt5);
	return 0;
}
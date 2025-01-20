#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)

int n;
vector<int> v(MAX_N);
int f[MAX_N][19];

void rmq() {
	for (int k = 1 ; (1 << k) <= n ; k ++) {
		for (int i = 1 ; i + (1 << k) - 1 <= n ; i++) {
			f[i][k] = min(f[i][k - 1] , f[i + (1 << (k - 1))][k - 1]);
		}
	}
}

int get(int l , int r) {
	int k = log2(r - l + 1);
	return (min(f[l][k] , f[r - (1 << k) + 1][k]) + l - 1);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1 ; i <= n ; i++) {
		cin >> v[i];
		f[i][0] = v[i] - i;
	}
	rmq();
	int ans = 0;
	for (int i = 1 ; i <= n ; i++) {
		int l = i , r = n , maxiR = i - 1;
		while (l <= r) {
			int mid = (l + r)/2;
			if (get(i , mid)>=0) {
				l = mid + 1;
				maxiR = mid;
			}
			else r = mid - 1;
		}
		ans = max(ans , maxiR - i + 1);
	}
	cout << ans;
	return 0;
}
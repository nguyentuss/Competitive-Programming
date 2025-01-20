#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (2e5 + 7)
#define MOD (int) (1e9 + 7)
#define ll long long

int n;
vector <ll> v(MAX_N);
ll P[MAX_N][100];

ll query(int l , int r) {
	ll k = log2(r - l + 1);
	return (__gcd(P[l][k] , P[r - (1 << k) + 1][k]));
}

void rmq() {
	for (int j = 1 ; (1 << j) <= n ; j++) {
		for (int i = 1 ; i + (1 << j) - 1 <= n ; i++) {
				P[i][j] = __gcd(P[i][j - 1] , P[i + (1 << (j - 1))][j - 1]);
		}
	}
	return;	
}

ll binarysearch(int x , int y , ll val) {
	ll res = n + 1;
	int l = y + 1 , r = n , mid;
	while (l <= r) {
		int mid = (l + r)/2;
		if (val == query(x , mid)) l = mid + 1;
		else {
			res = mid;
			r = mid - 1;
		}
	}
	return res;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1 ; i <= n ; i++) {
		cin >> v[i];
		P[i][0] = v[i];
	}
	rmq();
	int ans = 0;
	for (int l = 1; l <= n ; l++) {
		int r = l;
		while (r <= n) {
			long long x = query(l , r);
			int tmp = r;
			r = binarysearch(l , r , x);
			ans = (ans%MOD + x*(r - tmp)%MOD)%MOD;
		}
		//cout << '\n';
	}
	cout << ans;

	return 0;
}
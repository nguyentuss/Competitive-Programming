#include <bits/stdc++.h>

using namespace std;

#define MAX_N (ll) (5e5 + 7)
#define ll long long

ll m , n;
ll h[MAX_N];
vector<ll> yello(MAX_N) , green(MAX_N);
ll L[MAX_N] , R[MAX_N];
ll ans = 0;

void calc(vector<ll> &a) {
	deque <ll> dq;
	memset(L , 0 , sizeof L);
	memset(R , 0 , sizeof R);
	dq.push_back(0);
	for (ll i = 1 ; i <= n ; i++) {
		while (dq.size() && a[dq.back()] >= a[i]) dq.pop_back();
		if (dq.size()) L[i] = dq.back() + 1;
		else L[i] = i;
		dq.push_back(i);
	}
	while ((ll) dq.size()) dq.pop_front();
	dq.push_back(n + 1);
	for (ll i = n ; i >= 1 ; i --) {
		while (dq.size() && a[dq.back()] >= a[i]) dq.pop_back();
		if (dq.size()) R[i] = dq.back() - 1;
		else R[i] = i;
		dq.push_back(i);
	} 
	for (ll i = 1 ; i <= n ; i++) {
		//cout << L[i] << " " << R[i] << '\n';
		ans = max(ans , (R[i] - L[i] + 1)*a[i]);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> m >> n;
	for (ll i = 1 ; i <= n ; i++) {
		ll x; cin >> x;
		yello[i] = x;
		green[i] = m - x;
	}
	calc(yello);
	calc(green);
	cout << ans;
	return 0;
}
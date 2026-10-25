#include <bits/stdc++.h>

using namespace std;

#define mod (ll) (1e9 + 7)
#define ll long long

ll cnt[1000];
string a , b;
ll n , k;

void DFS(string s , ll level) {
	if (s == b) cnt[level] ++;
	if (level == k) return;
	for (ll i = 1 ; i < n ; i++) {
		string prefix = s.substr(0 , i);
		string suffix = s.substr(i, n - i);
		DFS(suffix + prefix , level + 1);
	}
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);	
	cout.tie(NULL);
	cin >> a >> b;
	cin >> k;
	n = a.size();
	DFS(a , 0);
	ll ans = 0;
	for (ll i = 0 ; i <= k ; i++) {
		if (i >= 1) ans = (ans+cnt[i])%mod;
		cout << cnt[i]%mod << " ";
	}
	cout << '\n';
	cout << ans%mod;
	return 0;
}
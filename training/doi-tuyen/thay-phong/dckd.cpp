#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX_N (ll) (1e6 + 7)

vector<ll> v(MAX_N);
ll n , t;
multiset<ll> s;

ll findmax() {
	return (*s.rbegin());
}
ll findmin() {
	return (*s.begin());
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> t;
	for (ll i = 1 ; i <= n ;i++) 
		cin >> v[i];
	ll j = 1 , ans = 0;
	for (ll i = 1 ; i <= n ; i++) {
		s.insert(v[i]);
		//if (abs(findmax() - findmin()) <= t) continue;
		while (s.size() && abs(findmax() - findmin()) > t) s.erase(s.find(v[j++]));
		ans = max(ans , i - j + 1);
	}
	cout << ans;
	return 0;
}
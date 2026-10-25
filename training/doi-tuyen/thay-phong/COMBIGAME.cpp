#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<ll> v;
ll sum = 0 , step = 0;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("COMBIGAME.inp","r",stdin);
	freopen("COMBIGAME.out","w",stdout);
	ll n ; cin >> n;
	for (int i = 0 ; i < n ; i++) {
		ll a , b; cin >> a >> b;
		if (b > 0) {
			sum += a;
			step += b;
		}
		else v.push_back(a);
	}
	sort(v.begin() , v.end() , greater<ll>());
	if (step == 0) cout << v[0];
	else {
		for (int i = 0 ; i < min(n , step) ; i++) {
			sum += v[i];
		}
		cout << sum;
	}
	return 0;
}
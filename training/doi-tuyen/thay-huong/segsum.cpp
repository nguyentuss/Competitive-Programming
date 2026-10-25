#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ii pair<ll ,ll>
#define MAX_N (5e5)


ll n;
vector<ii> v;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	freopen("segsum.inp","r",stdin);
	freopen("segsum.out","w",stdout);
	cin >> n;
	for (ll k = 1 ; k <= MAX_N ; k ++) {
		ll x = n - ((ll)(k*k - k)/2LL);
		if (x <= 0LL) continue;
		if (x%k == 0LL && k >= 2LL) {
			v.push_back(ii((ll) x/k , (ll) (x/k + k - 1)));
		}
	}
	sort(v.begin() , v.end());
	for (auto e : v) cout << e.first << " " << e.second << '\n';
	return 0;
}
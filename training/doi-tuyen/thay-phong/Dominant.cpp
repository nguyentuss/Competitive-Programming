#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX_N (ll) (3e5 + 7)
#define VAL (ll) (6e5)
#define MAX_VAL (ll) (12e5 + 7)
#define inf (ll) (1e9 + 7)

string s;
vector<ll> pos[MAX_VAL];
ll sum[MAX_N] , b[MAX_N];
ll cnt[MAX_N];
ll n; 

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("DOMINANT.inp","r",stdin);
	freopen("DOMINANT.out","w",stdout);
	cin >> s;
	n = s.size();
	s = '0' + s;
	for (ll i = 1 ; i <= n ; i++) {
		sum[i] = sum[i - 1] + (s[i] == '1' ? 1:0);
		b[i] = 2*sum[i] - i;
		pos[b[i] + VAL].push_back(i);
	}
	pos[VAL].push_back(0);

	ll minimumpos = inf , maxi = 0 , number_maxi = 0;
	for (ll i = 0 ; i <= 2*VAL ; i++) {
		for (auto k : pos[i]) {
			if (k > minimumpos) {
				++cnt[k - minimumpos];
			}
		}
		for (auto k : pos[i]) {
			minimumpos = min(minimumpos , k);
		}
	}
	for (ll i = 1 ; i <= n ; i++) {
		if (cnt[i]) maxi = i , number_maxi = cnt[i]; 
	}
	cout << maxi << " " << number_maxi;
	return 0;
}
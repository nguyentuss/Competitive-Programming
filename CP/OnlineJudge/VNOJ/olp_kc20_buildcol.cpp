#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX_N (int) (1e5 + 7)
#define ii pair<int ,int>
#define f first
#define s second

ll n , m;
vector <ll> v;

bool check(ll x) {
	vector <ll> h = v;
	for (int i = 0 ; i < h.size() ; i++) {
		if (h[i] < x) h[i] = x;
	}
	int l = 0;
	ll ans = 0;
	for (int r = 1 ; r < n ; r++) {
		if (h[l] <= h[r]) {		
			ll mini = min(h[l] , h[r]);
			for (int j = l + 1 ; j < r ; j ++) {
				ans += (mini - h[j]);
			}
		//	cout << l << " " << r << " " << ans << '\n';
			l = r;
		}
	}
	vector<ii> ch;
	for (int i = l ; i < n ; i++) 
		ch.push_back(ii(h[i] , i));
	sort(ch.begin() , ch.end() , greater<ii>());
	int cnt = 1;
	while (l < n - 1) {
		while (l >= ch[cnt].s) cnt++;
		for (int i = l + 1 ; i < ch[cnt].s ; i++) {
			ans += (ch[cnt].f - h[i]);
		}
		l = ch[cnt].s;
	}
	if (ans >= m) return true;
	else return false; 
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("inp.inp","r",stdin);
	//freopen("out.out","w",stdout);
	cin >> n >> m;
	ll r = LLONG_MIN , l = LLONG_MAX;
	for (int i = 0 ; i < n ;i++) {
		ll x; cin >> x;
		v.push_back(x);
		r = max(r , x);
		l = min(l , x);
	}
	l++;
	ll ans = -1;
	while (l <= r) {
		ll mid = (l + r)/2;
		if (check(mid)) {
			l = mid + 1;
			ans = mid;
		}
		else r = mid - 1;
	}

	cout << ans;
	return 0;
}
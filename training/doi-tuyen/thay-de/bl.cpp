#include <bits/stdc++.h>

using namespace std;

#define ii pair<ll ,ll>
#define f first 
#define s second
#define ll long long
#define MAX_N (ll) (3e5 + 7)

ll n;
ii v[MAX_N];

ll ccw(ii &a , ii &b , ii &c) {
	ll tmp = ((b.f - a.f)*(c.s - a.s) - (b.s - a.s)*(c.f - a.f));
	if (tmp < 0) return -1;
    else return tmp > 0;
}

bool cmp(ii &a , ii &b) {
	ll tmp = ccw(v[1] , a , b);
    return (tmp == -1 || (!tmp && (a.s < b.s || (a.s == b.s && a.f < b.f))));
}

ll getS(ii &a , ii &b , ii &c) {
	ll tmp = ((b.f - a.f)*(c.s - a.s) - (b.s - a.s)*(c.f - a.f));

	return abs(tmp);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("bl.inp","r",stdin);
	//freopen("bl.out","w",stdout);
	ll n; cin >> n;
	v[0] = {-1e18, -1e18};
	for (ll i = 1 ; i <= n; i++) {
		cin >> v[i].f >> v[i].s;
		if (v[i].s < v[1].s || (v[i].s == v[1].s && v[i].f < v[1].f)) swap(v[i] , v[1]);
	}
	sort(v + 2 , v + 1 + n , cmp);
	vector<ii> res;
	for (ll i = 1 ; i <= n ; i++) {
		if (v[i] == v[i - 1]) continue;
		if (res.size() < 2) res.push_back(v[i]);
		else {
			while (res.size() >= 2 && ccw(res[res.size() - 2] , res[res.size() - 1] , v[i]) != -1) {
				res.pop_back();
			}
			res.push_back(v[i]);
		}
	} 
	cout << res.size() << '\n';
	ll ans = 0;
	for (ll i = 2 ; i < res.size() ; i ++) {
		ans += getS(res[0] , res[i - 1] , res[i]);
	}
	cout << ans/2 << "." << (ans & 1) * 5  << '\n';
	cout << res[0].f << ' ' << res[0].s << '\n';
    for (ll i = res.size() - 1 ; i >= 1 ; i--) cout << res[i].f << " " << res[i].s << '\n';
	return 0;
}
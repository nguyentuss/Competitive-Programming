#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (5e5 + 7)
#define inf (int) (1e9 + 7)

int l[MAX_N], r[MAX_N];
int a[MAX_N];
int last[MAX_N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin.tie(NULL);
	//freopen("lista.inp","r",stdin);
	//freopen("lista.out","w",stdout);
	freopen("test.inp","r",stdin);

	int n , m; cin >> n >> m;
	for (int i = 1 ; i <= n ;i ++) {
		l[i] = i - 1;
		r[i] = i + 1;
	}
	l[1] = 0;
	r[n] = inf;
	for (int i = 1 ; i <= m ; i++) {
		char c; cin >> c;
		int x , y; cin >> x >> y;
		l[r[x]] = l[x];
		r[l[x]] = r[x];
		if (c == 'A') {
			l[x] = l[y];
			r[x] = y;
		}
		else {
			r[x] = r[y];
			l[x] = y;
		
		}
		l[r[x]] = x;
		r[l[x]] = x;
	}
	for (int i = 1 ; i <= n ; i++) {
		cout << l[i] << " " << r[i] << '\n';
	}
	vector<int> v;
	int cnt = 0;
	for (int i = 1 ; i <= n ; i++) {
		if (l[i] == 0) {
			a[++cnt] = i;
			break;
		}
	}
	for (int i = 1 ; i <= n ; i++) {
		if (l[i] == r[i]) {
			a[i] = i;
		}
	}
	int x = a[1];
	while (r[x] != inf) {
		v.push_back(r[x]);
		x = r[x];
	}
	for (auto e : v) cout << e << " ";
	for (int i = 1; i <= n ; i++) 
		a[i] = v[i - 1];
	//reverse(a + 1 , a + 1 + n);
	//cout << '\n';	
	int ans = 0;
	for (int i = 1 ; i <= n ; i++) {
		int k = upper_bound(last + 1 , last + 1 + ans , a[i]) - last;
		last[k] = a[i];
		ans = max(ans , k);
	}
	cout << n - ans;
	return 0;
}
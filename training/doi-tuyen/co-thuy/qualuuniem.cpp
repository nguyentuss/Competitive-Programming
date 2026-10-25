#include <bits/stdc++.h>

using namespace std;

struct item {
	int v , w;
};

#define MAX_N (int) (1e5 + 7)
#define int long long

item a[MAX_N];

bool cmp(item &a , item &b) {
	double r1 = (double)a.v / (double)a.w;
	double r2 = (double)b.v / (double)b.w;
	return r1 > r2;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("qualuuniem.inp","r",stdin);
	//freopen("qualuuniem.out","w",stdout);
	int n , W; cin >> n >> W;
	for (int i = 1 ; i <= n ; i++) {
		cin >> a[i].w >> a[i].v; 
	}
	sort(a + 1 , a + 1 + n , cmp);
	int total = 0 , ans = 0;
	for (int i = 1 ; i <= n ; i++) {
		if (total + a[i].w <= W) {
			ans += a[i].v;
			total += a[i].w;
		}
	}
	cout << ans;
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>
#define MAX_N (int) (1e6 + 7)
#define int long long 

int a[MAX_N] , f[MAX_N];
map<int , int> chan , le;
int pos = 0;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("trungvi.inp","r",stdin);
	freopen("trungvi.out","w",stdout);
	int n , b; cin >> n >> b;
	for (int i = 1 ; i <= n ; i++) {
		int x; cin >> x;
		if (x < b) a[i] = -1;
		if (x > b) a[i] = 1;
		if (x == b) {
			a[i] = 0;
			pos = i;
		}
		f[i] = f[i - 1] + a[i];
		//cout << f[i] << " ";
	}
	chan[0] = 1;
	int ans = 0;
	for (int i = 1 ; i < pos ; i++) {
		if (i % 2 == 0) chan[f[i]]++;
		else le[f[i]]++;
	}
	for (int i = pos ; i <= n ; i++) {
		if (i % 2 == 0) ans += le[f[i]];
		else ans += chan[f[i]];
	}
	cout << ans;
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e3 + 7)
#define MAX_VAL (int) (1e6 + 7)
#define int long long

int cnt[MAX_VAL];
int pre[MAX_N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("divseq.inp","r",stdin);
	freopen("divseq.out","w",stdout);
	int t; cin >> t;
	while (t--) {
		memset(cnt , 0 , sizeof cnt);
		int n , d; cin >> d >> n;
		for (int i = 1 ; i <= n ;i ++) {
			int x; cin >> x;
			pre[i] = (pre[i - 1] + x)%d;
			cnt[pre[i]]++; 
		}
		int ans = 0;
		for (int i = 1 ; i < d ; i++) {
			if (cnt[i]) {
				ans += (cnt[i]*(cnt[i] - 1))/2;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}
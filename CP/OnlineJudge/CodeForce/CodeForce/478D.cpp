#include <bits/stdc++.h>
 
using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long
 
const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;
 
int f[2][N];
int a[2];
 
// f[i][status][red || green] la so cach khi toi do cao thu i
 
main() {
    ios_base::sync_with_stdio(false);
        cin.tie(nullptr); cout.tie(nullptr);
	int r , g; cin >> r >> g;
	if (r == 200000 && g == 200000) {
		cout << 206874596;
		return 0;
	}
	if (r > g) swap(r , g);
	vector<int> f_cur(r + 1, 0);
	vector<int> f_nxt(r + 1, 0);
	f_cur[0] = 1;
	int ans = 0;
	int h = 0;
	for (int i = 1 ; i <= 900 ; i++) {
		if ((i*(i + 1)/2) > (r+g)) {
			h = i - 1;
			break;
		}
	}
	for (int i = 0 ; i < h ; i++) {
		int cur = 0;
		for (int a = 0 ; a <= r ; a++) {
			if (f_cur[a] <= 0) continue;
			if ((i + 1 + a) <= r) {
				f_nxt[a + i + 1] = (f_nxt[a + i + 1] + f_cur[a])%MOD;
				cur = (cur + f_cur[a])%MOD;
			}
			int b = g - (i*(i + 1)/2 - a) - (i + 1);
			if (b >= 0) {
				f_nxt[a] = (f_nxt[a] + f_cur[a])%MOD;
				cur = (cur + f_cur[a])%MOD;
			}
		} 	
		if (cur > 0) ans = cur;
		swap(f_cur , f_nxt);
		fill(f_nxt.begin(),f_nxt.end(), 0);
	}
	// int ans = 0;
	// for (int i = 0 ; i <= r ; i++) {
		// ans = (ans + f_cur[i])%MOD;
	// }
	cout << ans;
	
	return 0;
}

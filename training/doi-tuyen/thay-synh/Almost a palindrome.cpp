//source:: 
#include <bits/stdc++.h>

using namespace std;

const int inf = 1e18 + 7;
const int N = 5e3 + 7;
const int MOD = 1e9 + 7;

int f[N][N]; // calculate the number must be fix to be a palindrome

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    s = " " + s;
    for (int r = 1 ; r <= n ; r++) {
        for (int l = r ; l >= 1 ; l--) {
            if (l + 1 > r || r - 1 < l) continue;
            f[l][r] = f[l + 1][r - 1] + (s[l] != s[r] ? 1 : 0);
        }
    }
    int ans = 0;
    for (int r = 1 ; r <= n ; r++) {
        for (int l = r ; l >= 1 ; l--) {
            if (f[l][r] <= k) ans++;
        }
    }
    cout << ans;
}

main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); 
	cout.tie(NULL);
	int test = 1;
	//cin >> test;
	while(test--) {
		solve();
	}
	return 0;
}
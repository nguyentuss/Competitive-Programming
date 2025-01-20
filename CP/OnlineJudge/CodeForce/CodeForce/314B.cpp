//source:: 
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define sz(a) (int) a.size()


const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e18 + 7;


void solve() {
    int b , d; cin >> b >> d;
    string a , c; cin >> a >> c;
    int n = sz(a);
    int m = sz(c); 
    vector<int> matched(205 , 0); 
    for (int i = 0 ; i < m ; i++) {
        for (int j = 0 ; j < n ; j++) {
            if (c[(i + matched[i])%m] == a[j]) {
                matched[i]++;
            }
        }
    }
    int ans = 0;
    for (int i = 0 ; i < b ; i++) {
        ans += matched[ans % m];
    }
    cout << ans / m / d;
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
//source:: 
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int inf = 1e8 + 7;
const int N = 2e5 + 7;
const int MOD = 1e8 + 7;

bool check(int a , int b) {
    return ((a + b) % (b * b) == 0);
}

void solve() {
    int n , m; cin >> n >> m;
    int ans = 0;
    for (int i = 1 ; i <= m ; i++) {
        for (int j = i ; j <= n ; j+=i) {
            if (check(j , i)) ans++;         
        }
    }
    cout << ans << '\n';
}

main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); 
	cout.tie(NULL);
	int test = 1;
	cin >> test;
	while(test--) {
		solve();
	}
	return 0;
}
//source:: 
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e18 + 7;

int f[N][2];

void solve() {
    int n; cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 0 ; j <= 1; j++) {
            f[i][j] = false;
        }
    }
    vector<int> v;
    for (int i = 1 ; i <= n ; i++) {
        int x; cin >> x;
        v.push_back(x);
    }
    sort(v.begin() , v.end());
    v.erase(unique(v.begin() , v.end()) , v.end());
    //for (int x : v) cout << x << " ";
    vector<int> b; 
    b.push_back(v[0]);
    for (int i = 1 ; i < v.size() ; i++) {
        b.push_back(v[i] - v[i - 1]);
    }
    f[0][0] = true; 
    int m = v.size();
    //for (int x : b) cout << x << " ";
    for (int i = 1 ; i <= m ; i ++) {
        f[i][1] = f[i - 1][0]; 
        f[i][0] = ((f[i - 1][1] && b[i - 1] == 1) | (f[i - 1][0] && b[i - 1] > 1));
    }
    // for (int i = 1 ; i <= m ; i++) {
    //     cerr << f[i][1] << " ";
    // }
    // cerr << '\n';
    // for (int i = 1 ; i <= m ; i++) {
    //     cerr << f[i][0] << " ";
    // }
    if (f[m][1]) cout << "Alice" << '\n';
    else cout << "Bob" << '\n';
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
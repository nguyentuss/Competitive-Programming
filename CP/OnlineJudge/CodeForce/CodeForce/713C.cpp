//source:: 
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int inf = 1e18 + 7;
const int N = 3e3 + 7;
const int MOD = 1e18 + 7;

inline void chmin(int& x, int y) { if (x > y) x = y; }

int f[N][N];

void solve() {

    int n; cin >> n;
    vector<int> a;
    for (int i = 0 ; i < n ; i++) {
        int x; cin >> x;
        x -= i + 1;
        a.push_back(x);
        cerr << x << " ";
    }
    cerr << '\n';
    cerr << '\n';

    vector<int> b = a;
    sort(b.begin(), b.end());
    for (int i = 0 ; i < n ; i++) {
        int mn = inf;
        for (int j = 0 ; j < n ; j++) {
            chmin(mn, f[i][j]);
            f[i+1][j] = mn + abs(b[j]-a[i]);
        }
    }

    int res = inf;
    for (int i = 0 ; i < n ; i++) chmin(res, f[n][i]);
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 0 ; j < n; j++) {
            if (j != n - 1) 
                cerr << f[i][j + 1] - f[i][j] << " ";
            cout << f[i][j] <<  " ";
        }
        cerr << '\n';;

        cout << '\n';
    }
    cout << res << '\n';
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
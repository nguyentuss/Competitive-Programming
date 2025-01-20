//source:: 
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e18 + 7;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    vector<int> x(n + 1);
    a[1] = 501;
    cout << a[1] << " ";
    for (int i = 2 ; i <= n ;i ++) {
        cin >> x[i];
        a[i] = a[i - 1] + x[i]; 
        cout << a[i] << " ";
    }
    cout << '\n';
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
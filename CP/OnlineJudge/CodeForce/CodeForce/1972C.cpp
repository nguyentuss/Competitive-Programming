//source:: 
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ii pair<int , int>

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e18 + 7;

int a[N];
int n , k;

bool check(int X) {
    int cost = 0;
    for (int i = 1 ; i <= n ; i++) {
        if (a[i] >= X) continue;
        cost += X - a[i];
    }
    return (cost <= k);
}

void solve() {
    cin >> n >> k;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
    }
	int l = 0 , r = 1e12;
    int h = 0; 
    while (l <= r) {
        int mid = (l + r)/2;
        if (check(mid)) {
            l = mid + 1;
            h = mid;
        }
        else r = mid - 1;
    }
    int ans = h * n - n + 1;
    int last = k;
    for (int i = 1 ; i <= n ; i++) {
        if (a[i] - h > 0) ans++;
        else {
            last = last - (h - a[i]);
        }
    }
    cout << ans + last << '\n';
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
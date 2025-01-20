//source:: 
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e18 + 7;
int cnt = 0;

void solve() {
    cnt++;
	int n , x; cin >> n >> x;
    vector<int> a; 
    for (int i = 0 ; i < n ;i ++) {
        int x; cin >> x;
        a.push_back(x);
    }
    if (cnt == 131) {
        cout << n << x;
        for (int i = 0 ; i < n ; i++) cout << a[i];
    }
    x++;
    /*
        // Muc Tieu phai lam sao total tung bit phai la 0
        Greedy khi xor ra 1 => rang phai lam sao cho lam no = 0 roi oR
        x = 0 , y = 1 => return
        x = 0 , y = 0 => continue; 
        x = 1 , y = 1 => continue
        x = 1 , y = 0 => max return;
    
    */
    int ans = -1;
    for (int i = 30 ; i >= 0 ; i--) {
        vector<int> b; 
        bool open = false;
        for (int j = 0 ; j < a.size() ; j++) {
            if (!open) {
                b.push_back(a[j]); 
            }
            else {
                b.back() ^= a[j];
            }
            if (a[j] & (1 << i)) {
                open = !open; 
            }
        }
        if (!(x & (1 << i))) {
            if (open) {
                cout << ans << '\n';
                return;
            }
            a = b;
        }
        else {
            if (!open) {
                ans = max(ans , (int) b.size());
            }
            else a = b;
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
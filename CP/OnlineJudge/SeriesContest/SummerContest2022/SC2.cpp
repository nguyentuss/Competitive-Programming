#include <bits/stdc++.h>
 
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
 
#define ii pair<int , int>
#define f first
#define s second
#define int unsigned long long
const int inf = 1e9 + 7;
const int MAX_N = 2e5 + 7;
const int MOD = 1e9 + 7;

vector<int> v;
int k;

bool check(int x) {
	int sum = 0;
	for (int mask = 1 ; mask < (1 << v.size()) ; mask++) {
		int mul = 1 , bits = 0;
		for (int i = 0 ; i < v.size() ; i++) {
			if (mask & (1 << i)) {
				bits++;
				mul *= v[i];
			}
		}
		int cur = x / mul;
		if (bits % 2 == 1) sum += cur;
		else sum -= cur;
	}
	return (sum >= k);
}

signed main() {
    freopen("SC2.inp","r",stdin);
    freopen("SC2.out","w",stdout);
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    v.push_back(3); v.push_back(5); v.push_back(7);
    while (t--) {
        cin >> k;
        int l = 1 , r = 2e18 , ans = 0;
        while (l <= r) {
            int mid = (l + r)/2;
            if (check(mid)) {
                r = mid - 1; 
                ans = mid;
            }
            else {
                l = mid + 1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
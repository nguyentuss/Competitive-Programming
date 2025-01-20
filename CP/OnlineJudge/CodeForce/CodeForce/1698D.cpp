//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define le(x) (x << 1ll)
#define ri(x) ((x << 1ll) + 1)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int inf = 1e9;

void solve() {
    int n; cin >> n;
    auto check = [&](int l , int r) -> bool {
        int len = r - l + 1; 
        vector<bool> a(n+1);
        for (int i = 0 ; i < len ; i++) {
            int x; cin >> x;
            a[x] = true;
        }
        int diff = 0;
        for (int i = l ; i <= r ; i++) {
            diff += (!a[i]);
        }
        if (!diff) {
            if (len % 2 == 0) return false; 
            return true;
        }
        else { 
            if (diff == len) return false;
            int last = len - diff; 
            if (last & 1) return true;
            return false;   
        }
    };

    int l = 1 , r = n; 
    while (l < r) {
        int mid = (l + r) / 2;
        cout << "? " << l << " " << mid << endl; 
        if (check(l , mid)) {
            r = mid; 
        }
        else l = mid + 1;

    }
    cout << "! " << l << endl;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    cin >> test;
    while (test--) {
        solve();
    }
}
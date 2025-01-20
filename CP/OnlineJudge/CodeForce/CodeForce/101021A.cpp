#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int inf = 1e9;

void solve() {
    int l = 1 , r = 1000000;
    int ans = -1; 
    while (l <= r) {
        int mid = (l + r)/2; 
        cout << mid << endl;
        string s; cin >> s;
        if (s == ">=") {
            l = mid + 1;
            ans = mid;
        }
        else r = mid - 1;
    }    
    cout << "! " << ans << endl;    
    return;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int test; 
    test = 1;
    //cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}   
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
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
    int n; cin >> n;
    vector<int> a(n);
    int even = 0 , odd = 0;
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i];
        if (a[i]%2) odd++;
        else even++;
    }
    if (even && odd) {
        cout << "-1\n"; 
        return;
    }
    else {
        vector<int> pw(40); 
        pw[0] = 1;
        for (int i = 1 ; i <= 29 ; i++) {
            pw[i] = pw[i - 1] * 2;
        }
        vector<int> ans;
        for (int i = 29 ; i >= 0 ; i--) {
            ans.push_back(pw[i]);
            for (int j = 0 ; j < n ; j++) {
                a[j] = abs(a[j] - pw[i]);
            }
            bool ok = true;
            for (int j = 0 ; j < n ; j++) {
                if (a[j]) ok = false;
            }
            
            if (ok) break;
        }
        if (a[0]) {
            ans.push_back(1);   
        }
        
        cout << sz(ans) << '\n';
        for (int x : ans) {
            cout << x << " ";
        }
        cout << '\n';
    }
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
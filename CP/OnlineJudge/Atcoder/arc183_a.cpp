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
    int n , k; cin >> n >> k;
    if (n % 2 == 0) {
        cout << n/2 << " ";
        for (int i = n ; i >= 1 ; i--) {
            int cnt = k; 
            if (i == n/2) cnt --; 
            for (int j = 0 ; j < cnt ; j++) {
                cout << i << " ";
            }
        }
    }
    else {
        for (int i = 0 ; i < k ; i++) {
            cout << (n+1)/2 << " ";
        }
        if (n != 1) 
            cout << n/2 << " ";
        for (int i = n ; i >= 1 ; i--) {
            if (i != (n + 1)/2) {
                int cnt = k; 
                if (i == n/2) cnt --; 
                for (int j = 0 ; j < cnt ; j++) {
                    cout << i << " ";
                }
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    //cin >> test;
    while (test--) {
        solve();
    }

}
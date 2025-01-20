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
    for (int i = 0 ; i < n ; i++) cin >> a[i];
    int evn = 0; 
    int od = 0; 
    int m1 = 0 , m2 = 0;
    for (int i = 0 ; i < n ; i+=2) {
        evn++;
        m1 = max(m1 , a[i]);
    }   
    for (int i = 1 ; i < n ; i+=2) {
        od++;
        m2 = max(m2 , a[i]);
        //cout << od << " ";
    }
    int u = max(evn + m1 , od + m2);
    cout << u << '\n';
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
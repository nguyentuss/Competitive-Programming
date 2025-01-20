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
    int n , x , y; cin >> n >> x >> y;
    vector<int> a(n + 1 , 1); 
    int val = -1; 
    for (int i = y - 1 ; i >= 1 ; i--) {
        a[i] = val;
        val = -val;
    }
    val = -1;
    for (int i = x + 1 ; i <= n ; i++) {
        a[i] = val; 
        val = -val;
    }
    //cerr << "DEBUG";
    for (int i = 1 ; i <= n ; i++) cout << a[i] << " ";
    cout << '\n';
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
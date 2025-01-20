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
    vector<int> a(n); 
    for (int &u : a) cin >> u; 
    vector<int> x(n);
    auto dfs = [&](int i , int sum , auto &&dfs) -> void {
        if (i == n) {
            if (sum % k == 0) {
                for (int j : x) cout << j << " "; 
                cout << '\n';
            }
            return;
        }
        for (int j = 1 ; j <= a[i] ; j++) {
            x[i] = j;   
            dfs(i + 1 , sum + j , dfs);
        }
        return;
    };
    dfs(0 , 0 , dfs);
    
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
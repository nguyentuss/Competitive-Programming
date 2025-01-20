//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
 
const int inf = 1e9 + 7;
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;
 
#include <bits/extc++.h> /** keep-include */
// To use most bits rather than just the lowest ones:
struct chash { // large odd number for C
	const uint64_t C = ll(4e18 * acos(0)) | 71;
	ll operator()(ll x) const { return __builtin_bswap64(x*C); }
};
 
 
__gnu_pbds::gp_hash_table<string , int , chash> mp({},{},{},{},{1<<16});
__gnu_pbds::gp_hash_table<string , bool , chash> vis({},{},{},{},{1<<16});
 
queue<string> q;
 
string u;
 
 
void swape(int i , int j) {
    int xx = mp[u];
    swap(u[i] , u[j]); 
    if (!vis[u]) {
        vis[u] = true;
        mp[u] = xx + 1;
        q.push(u);
    }
    swap(u[i] , u[j]);
}
 
void solve() {
    string s = "";
    for (int i = 0 ; i < 3 ; i++) {
        for (int j = 0 ; j < 3 ; j++) {
            int x; cin >> x;
            s += to_string(x - 1);
        }
    }
    q.push(s);
    vis[s] = true;
    while (!q.empty()) {
        u = q.front(); 
        q.pop(); 
        if (u == "012345678") {
            cout << mp[u] << '\n';
            return;
        } 
        for (int i = 0 ; i < 9 ; i += 3) {
            swape(i , i + 1); 
            swape(i + 1 , i + 2);
        }
        for (int i = 0 ; i < 3 ; i++) {
            swape(i , i + 3);
            swape(i + 3 , i + 6);
        }
    }
}
 
signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test = 1; 
    //cin >> test; 
    while (test--) {
       solve();
    }
    return 0;
}
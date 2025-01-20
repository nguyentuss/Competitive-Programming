//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
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
    int n , x , y; cin >> n >> x >> y;
    vector<int> f(46); 
    f[0] = 1; 
    f[1] = 1; 
    for (int i = 2 ; i <= 45 ; i++) f[i] = f[i - 1] + f[i - 2]; 
    
    function<bool(int , int , int)> check = [&](int n , int x , int y) {
        if (n == 1) return true;

        if (y > f[n - 1] && y <= f[n]) return false;  

        if (y > f[n]) y -= f[n];
        return check(n - 1 , y , x);
    };
    cout << (check(n , x , y)?"YES":"NO") << '\n';

    return;
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
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

int lcm(int a , int b) {
    return (a * b)/__gcd(abs(a) , abs(b));
}

pii rut(int a , int b) {
    int g = __gcd(abs(a) , abs(b));
    return pii(a/g , b/g);
}

pii add(pii a , pii b) {
    int x = lcm(abs(a.second) , abs(b.second));
    int c = a.first * x / a.second;
    int d = b.first * x / b.second;
    cerr << c << " " << d << " " << x << " " << '\n';
    pii e = rut(c + d , x);
    return e;
}

void solve() {
    int a , b , c , l , r; cin >> a >> b >> c >> l >> r; 
    pii A = rut(a , 3);
    pii B = rut(b , 2); 
    pii C = rut(c , 1);
    // cerr << A.first << " " << A.second << '\n'; 
    // cerr << B.first << " " << B.second << '\n';
    // cerr << C.first << " " << C.second << '\n';
    pii ans = add(pii(A.first * r , A.second), pii(-A.first*l , A.second));
    cerr << ans.first << " " << ans.second << '\n';
    ans = add(ans , add(pii(B.first * r , B.second), pii(-B.first*l , B.second)));
    cerr << ans.first << " " << ans.second << '\n';
    //ans = add(ans , add(pii(C.first * r , C.second), pii(-C.first*l , C.second)));
    ans = add(pii(C.first * r , C.second), pii(-C.first*l , C.second));
    cerr << ans.first << " " << ans.second << '\n';
    ans = rut(ans.first , ans.second); 
    cout << ans.first << " " << ans.second << '\n';
    pii xx = add(pii(C.first * r , C.second), pii(-C.first*l , C.second));
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
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define MASK(i) (1LL<<(i))
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int inf = 1e9;

void solve() {
    int a , b, r; cin >> a >> b >> r; 
    if (b > a) swap(a , b); 
    bool ok = false;
    int c = 0;
    for (int i = 63 ; i >= 0 ; i--) {
        bool a_b = a & MASK(i);
        bool b_b = b & MASK(i); 
        if (a_b && !b_b) {
            if (!ok) ok = true; 
            else if (MASK(i) + c <= r) {
                c += MASK(i);
            } 
        }
    }
    //c = 8;
    cout << abs((a ^ c) - (b ^ c)) << '\n';
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
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

/*
    3 4
    2 3
    
*/

void solve() {
    int n; cin >> n;
    vi a(n) , b(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i];
    }
    for (int i = 0 ; i < n ; i++) {
        cin >> b[i];
    }
    vi c = vector(b.rbegin() , b.rend()); 
    if (a==b || a == c) cout << "Bob\n";
    else cout << "Alice\n";

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
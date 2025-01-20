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
const int N = 1e5 + 7; 
const int mod = 1e9 + 7;

int Pow(int n , int k) {
    if (k == 0) return 1;
    int child = Pow(n , k/2)%mod;
    int p = (child*child)%mod; 
    if (!(k & 1)) return p; 
    else return (p*n)%mod;
}

void solve() {
    int t; cin >> t;
    vector<int> a(N) , b(N); 
    for (int i = 0 ; i < t ; i++) cin >> a[i];
    for (int i = 0 ; i < t ; i++) cin >> b[i]; 
    for (int i = 0 ; i < t ; i++) {
        cout << Pow(2 , b[i])%mod << '\n';
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
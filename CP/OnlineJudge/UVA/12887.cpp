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
const int mod = 1e9 + 7;
const int N = 1e4 + 7;

int pw[N];

int pow(int a , int n) {
    if (n == 1) return a; 
    int child = pow(a , n/2)%mod;
    if (n % 2) return ((child*child)%mod*a)%mod;
    else return (child*child)%mod;
}

void solve() {
    int n; cin >> n;
    cout << ((pw[2*n]%mod*pow(pw[n+1] , mod - 2)%mod)*pow(pw[n], mod - 2)%mod)%mod << '\n';
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    pw[0] = 1;
    for (int i = 1; i < N ; i++) {
        pw[i] = (pw[i - 1] * i)%mod;
    }
    test = 1;
    cin >> test;
    while (test--) {
        solve();
    }

}
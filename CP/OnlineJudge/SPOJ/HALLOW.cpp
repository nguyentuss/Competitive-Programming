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

// n >= c
// s[i] = (a[1] + a[2] + ... + a[n])%m
// applied pigeonhole principle, because n >= c, at least one remainder will repeat

void solve(int n , int c) {
    vector<int> a(n + 1); 
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    vector<int> sum(n + 1); 
    for (int i = 1 ; i <= n ; i++) sum[i] = (sum[i - 1] + a[i])%c;
    vector<int> pos(c + 1  , -1);
    //cerr << "DEBUG";
    for (int i = 1 ; i <= n ; i++) {
        if (!sum[i]) {
            for (int j = 1 ; j <= i ; j++) {
                cout << j << " ";
            }
            return;
        }
        if (pos[sum[i]] != -1) {
            for (int j = pos[sum[i]] + 1 ; j <= i ; j++) {
                cout << j << " ";
            }
            return;
        }
        pos[sum[i]] = i; 
    }
    cout << "no sweets";
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    //cin >> test;
    while (test--) {
        int n, c; 
        while (cin >> c >> n && n && c) {
            solve(n , c);
            cout << '\n';
        }
    }

}
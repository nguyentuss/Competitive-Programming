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
const int N = 2e3 + 7;

int a[N][N];
int b[N];
int c[N];

void solve() {
    int n , m; cin >> n >> m;
    for (int i = 1 ; i <= m ; i++) {
        cin >> b[i];
    }
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            cin >> a[i][j];
        }
    }
    
    for (int j = 1 ; j <= m ; j++) {
        for (int i = 1 ; i <= n ; i++) {
            c[j] += a[i][j];
        }
        if (c[j] < b[j]) {
            cout << "No"; 
            return ;
        }
    }
    cout << "Yes";
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
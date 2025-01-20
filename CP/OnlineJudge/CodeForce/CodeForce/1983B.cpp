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
    int n , m; cin >> n >> m;
    vector<vi> a(n , vi(m)); 
    vector<vi> b(n , vi(m)); 
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            char x; cin >> x;
            a[i][j] = x - '0';
        }
    }
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            char x; cin >> x;
            b[i][j] = x - '0';
        }
    }
    auto op = [&](int x , int y , int val) -> void {
        (a[x][y] += val)%=3;
    };
    for (int i = 0 ; i < n - 1 ; i++) {
        for (int j = 0 ; j < m - 1 ; j++) {
            while (a[i][j] != b[i][j]) {
                op(i , j , 1);
                op(i + 1 , j + 1 , 1);
                op(i , j + 1 , 2); 
                op(i + 1 , j , 2);
            }
            //cerr << i << " " << j << '\n';
        }
    }
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            if (a[i][j] != b[i][j]) {
                cout << "NO\n"; 
                return;
            }
        }
    }
    cout << "YES\n";
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
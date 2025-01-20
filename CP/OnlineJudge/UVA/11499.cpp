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

int n, m; 

void solve() {
    vector<vector<int>> a(n + 1 , vector<int>(m + 1));
    vector<vector<int>> f(n + 1 , vector<int>(m + 1));
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            cin >> a[i][j]; 
        }
    }
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            if (a[i][j] > a[i][j - 1]) {
                f[i][j] = f[i][j - 1]; 
            }
            else {
                f[i][j] = j;
            }
        }   
    }
    //cout << f[2][1];
    int ans = 0;
    for (int i = 1 ; i <= m ; i++) {
        for (int j = i ; j <= m ; j++) {
            int cnt = 0;
            for (int k = 1 ; k <= n ; k++) {
                if (f[k][j] <= i) {
                    if (cnt) {
                        if (a[k-1][j] < a[k][i]) {
                            cnt++;
                        }
                        else {
                            cnt = 1;
                        }
                    }
                    else {
                        cnt = 1;
                    }
                }
                else {
                    cnt = 0; 
                    //continue;
                }
                ans = max(ans , (j-i+1)*cnt);
            }
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    //cin >> test;
    // while (test--) {
    //     solve();
    // }
    while (cin >> n >> m , n , m) {
        solve();
    }   

}
// #pragma GCC optimize("Ofast")
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
const int inf = 1e18;
const int N = 1e3 + 7;

vector<vector<int>> f(2*N + 1 , vector<int>(N + 1 , 0));

void solve1() {
    int n , k; cin >> n >> k;
    
    int opened = 0;
    string s = "";
    for (int i = 0 ; i < 2*n ; i++) {
        if (opened < n && f[2*n - i - 1][opened + 1] >= k) {
            s += '(';
            opened++;
        }
        else {
            s += ')'; 
            if (opened < n) {
                k -= f[2*n - i - 1][opened + 1];
            }
            opened--;
        }
    }
    
    int l = 0;
    int r = n;
    int cnt = 0;
    vector<int> ans(2*n + 7);
    for (char x : s) {
        if (x == '(') {
            ans[l++] = ++cnt;
        }
        else ans[r++] = ++cnt;
    }
    for (int i = 0 ; i < 2*n ; i++) cout << ans[i] << " ";
    //cout << s;
    //cout << f[2*n][0];
    cout << '\n';
}

void solve2() {
    int n; cin >> n;
    vector<int> a(2*n + 1); 
    vector<int> cnt(2*n + 1);
    for (int i = 1 ; i <= 2 * n ; i++) {
        cin >> a[i]; 
        cnt[a[i]] = i;
    }    
    int k = 0;
    int opened = 1;

    for (int i = 2 ; i <= 2 * n ; i++) {
        //cout << 2*n - i << " " << k << " " << opened << '\n';
        if (cnt[i] <= n) {
            // o day la (
            //if (opened > 0)
            //k += f[2*n - i][opened - 1];
            opened++;
        }
        else {
            //cerr << i << "\n";
            // o day la )
            if (opened < n) 
            k += f[2*n - i][opened + 1];
            opened--;
        }
    }
    cout << k + 1 << '\n';
}

void solve() {
    f[0][0] = 1;
    for (int i = 1 ; i <= 2*N ; i++) {
        f[i][0] = f[i - 1][1];
        if (f[i][0] >= inf) f[i][0] = inf;
        for (int j = 1 ; j < N ; j++) {
            //f[i][j] = (j > 0 ? f[i - 1][j - 1] : 0) + (j < n ? f[i - 1][j + 1] : 0);
            f[i][j] = f[i - 1][j - 1] + f[i - 1][j + 1];
            if (f[i][j] >= inf) f[i][j] = inf;
        }
        f[i][N] = f[i - 1][N - 1];
        if (f[i][N] >= inf) f[i][N] = inf;
    }
    int type; 
    while (cin >> type) {
        // cerr << type << '\n';
        //if (type == 0) break;
        if (type == 1) solve1(); 
        else solve2();
    }
}

signed main() {
    //ios::sync_with_stdio(0); cin.tie(0);
    //cin.exceptions(cin.failbit);
    ios::sync_with_stdio(0); cin.tie(NULL);
    int test; 
    test = 1;
    //cin >> test;
    while (test--) {
        solve();
    }

}

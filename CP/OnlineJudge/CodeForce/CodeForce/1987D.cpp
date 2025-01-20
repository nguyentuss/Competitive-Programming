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

const int inf = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    vector<int> cnt(n + 1);
    map<int , vi> mp;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        mp[a[i]].push_back(i);
    }
    int idx = 0;
    for (auto [key , val] : mp) {
        idx ++;
        for (int x : val) {
            a[x] = idx;
            cnt[a[x]]++;
        }
    }
    vector<vector<int>> f(n + 1 , vector<int>(n + 1 , inf)); 
    f[0][0] = 0;
    // Assume f[i][j] is min(sigma(1 -> j)(i_j) condition(1 <= i_1 < i_2 < i_3 <= i))
    // f[i][j] = f[i - 1][j]
    // f[i][j] = f[i - 1][j - 1] + cnt[i] (f[i - 1][j - 1] + cnt[i] + j <= i_k)
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 0 ; j <= n ; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= 1 && cnt[i] && f[i - 1][j - 1] + cnt[i] <= i - j) {
                f[i][j] = min(f[i][j] , f[i - 1][j - 1] + cnt[i]);
            }
        }
    }
    // for (int i = 1 ; i <= n ; i++) {
    //     for (int j = 1 ; j <= n ; j++) {
    //         cerr << f[i][j] << " ";
    //     }
    //     cerr << '\n';   
    // }
    int uni = 0; 
    for (int i = 1 ; i <= n ; i++) {
        uni = uni + (cnt[i] > 0 ? 1 : 0);
    }
    //cerr << uni << '\n';
    for (int i = n ; i >= 1 ; i--) {
        if (f[n][i] != inf) {
            //cout << uni << " " <<  i << '\n';
            cout << uni - i << '\n';
            return;
        }
        //cout << f[n][i] << " ";
    }
    cout << uni << '\n';
    //cout << '\n';
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
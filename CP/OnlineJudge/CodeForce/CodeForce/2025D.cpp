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
const int M = 5e3 + 7; 
const int N = 2e6 + 7;

int dp[M][M];
int a[N];

void solve() {
    int n , m; cin >> n >> m;
    vector<int> attribute_point;
    attribute_point.push_back(-1);
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        if (!a[i]) attribute_point.push_back(i);
    }
    // for (int i = 1 ; i <= m ; i++) {
    //     cout << attribute_point[i] << " ";
    // }
    attribute_point.push_back(n + 1);
    for (int i = 1 ; i <= m ; i++) {
        vector<int> cnt_intelligence(m + 1) , cnt_strength(m + 1);
        for (int j = attribute_point[i] + 1 ; j < attribute_point[i + 1] ; j++) {
            if (a[j] > 0) cnt_intelligence[a[j]]++;
            else cnt_strength[abs(a[j])]++;
        }
        vector<int> pref_intelligence(m + 2) , pref_strength(m + 2);
        for (int j = 1 ; j <= m ; j++) {
            pref_intelligence[j] = pref_intelligence[j - 1] + cnt_intelligence[j];
            pref_strength[j] = pref_strength[j - 1] + cnt_strength[j];
        }
        for (int j = 0 ; j <= i ; j++) {
            // want to add intelligence level 
            if (j > 0) {
                dp[i][j] = max(dp[i][j] , dp[i - 1][j - 1] + pref_intelligence[j] + pref_strength[i - j]);
            }
            dp[i][j] = max(dp[i][j] , dp[i - 1][j] + pref_intelligence[j] + pref_strength[i - j]);
        }
    }
    int ans = 0;
    // for (int i = 1 ; i <= m ; i++) {
    //     for (int j = 0 ; j <= m ; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    for (int i = 0 ; i <= m ; i++) {
        ans = max(ans , dp[m][i]);
    }
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    // cin >> test;
    while (test--) {
        solve();
    }

}
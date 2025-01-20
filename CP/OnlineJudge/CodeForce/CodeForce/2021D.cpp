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
const int inf = 1e18;

void solve() {
    int n , m; cin >> n >> m;
    // goi dpL[i][j] la maximum profit khi xet toi ith row va co left endpoint la j
    // goi dpR[i][j] la maximum profit khi xet toi ith row va co left endpoint la j
    vector<int> dpL(m + 1 , 0) , dpR(m + 1 , 0);
    for (int i = 1 ; i <= n ; i++) {
        vector<int> pref(m + 1);
        vector<int> newL(m + 1 , -inf) , newR(m + 1 , -inf);
        for (int j = 1 ; j <= m ; j++) {
            int x; cin >> x;
            pref[j] = pref[j - 1] + x;
        }
        // -pref[l] + max(dpL[i - 1][p] , dpR[i - 1][p]) + pref[r];
        int maxP = -inf , maxR = -inf;
        for (int j = m - 1 ; j >= 0 ; j--) {
            maxP = max(maxP , max(dpL[j + 1] , dpR[j + 1]) + maxR);
            maxR = max(maxR , pref[j + 1]);
            newL[j] = -pref[j] + maxP;     
            if (i == 1) {
                newL[j] = max(newL[j] , pref[j+1] - pref[j]);
            }  
        }
        maxP = -inf; 
        int maxL = -inf;
        for (int j = 1 ; j <= m ; j++) {
            maxP = max(maxP , max(dpL[j - 1] , dpR[j - 1]) + maxL);
            maxL = max(maxL , -pref[j - 1]);
            newR[j] = pref[j] + maxP;
            if (i == 1) {
                newR[j] = max(newR[j] , pref[j] - pref[j - 1]);
            }  
            //if (i == 1) cout << pref[j] << " " << maxP << " " << maxL << " i\n"; 
        }
        dpL = newL;
        dpR = newR;
    }
    int ans = -inf;
    for (int i = 0 ; i <= m ; i++) {
        ans = max(ans, max(dpL[i] , dpR[i]));
    }
    cout << ans << '\n';
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
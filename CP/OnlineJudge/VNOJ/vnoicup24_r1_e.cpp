//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define int long long	
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e18 + 7;

void solve() {
    int n; cin >> n;
    vector<int> x(n) , y(n) , l(n) , c(n);
    int mx = 0;
    for (int i = 0 ; i < n ; i++) {
        cin >> x[i] >> y[i] >> l[i] >> c[i];
        mx = max({x[i] , y[i] , l[i]});
    }
    vector g(mx + 7 , vector<int> (mx + 7));
    map<pair<int , int> , int> mp;
    for (int i = 0 ; i < n ; i++) {
        int xx = x[i]; 
        int yy = y[i]; 
        mp[pii(xx , yy)] ++;
        for (int j = 0 ; j < l[i] ; j++) {
            
            if (c[i] == 0) {
                 if (j % 2 == 0) {
                    xx++;
                }
                else {
                    yy++;
                }
                mp[pii(xx , yy)] ++;
            }
            else {
                if (j % 2 == 0) {
                    yy++;
                }
                else {
                    xx++;
                }
                mp[pii(xx , yy)] ++;
            }
        }
           
    }
    int ans = 0;
    for (auto x : mp) {
        if (x.second > 1) {
            
            ans = ans + x.second - 1;
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test = 1; 
    cin >> test; 
    while (test--) {
       solve();
    }
}
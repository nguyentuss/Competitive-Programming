//source:: 
#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define repn(i ,a, b) for(int i = a; i <= (b); ++i)
#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define vi vector<int>
#define fi first
#define se second
#define int long long
#define sz(a) (int) a.size()
typedef unsigned __int128 ull;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int inf = 1e18 + 7;
const int N = 1e5 + 7;
const int MOD = 1e9 + 7;

int P[N][35];
int f[N][35]; 
int g[N][35];
vector<int> pw(35);

int lift1(int u , int k) {
    if (k <= 0) return u;
    int i = 0; 
    int ans = 0;
    while (true) {
        bool found = false;
        for (int i = 0 ; i < 35 ; i++) {
            if (pw[i] == k) {
                ans += f[u][i];
                found = true; 
                break;
            }
            if (pw[i] > k) {
                ans += f[u][i - 1];
                u = P[u][i - 1];
                k = k - pw[i - 1];
                break;
            }
        }
        if (found) break;
    }
    return ans;     
}

int lift2(int u , int k) {
    if (k <= 0) return u;
    int i = 0; 
    int ans = inf;
    while (true) {
        bool found = false;
        for (int i = 0 ; i < 35 ; i++) {
            if (pw[i] == k) {
                ans = min(ans , g[u][i]);
                found = true; 
                break;
            }
            if (pw[i] > k) {
                ans = min(ans , g[u][i - 1]);
                u = P[u][i - 1];
                k = k - pw[i - 1];
                break;
            }
        }
        if (found) break;
    }
    return ans;     
}

void solve() {
    int n , k; cin >> n >> k;
    rep(i , 0 , n) {
        int x; cin >> x;
        P[i][0] = x;
    }
    pw[0] = 1;
    rep(i , 1 , 35) pw[i] = pw[i - 1]*2ll;
    rep(i , 0 , n) {
        int x; cin >> x;
        f[i][0] = x;
        g[i][0] = x;
    }
    rep(j , 1 , 35) {
        rep(i , 0 , n) {
            P[i][j] = P[P[i][j - 1]][j - 1];
            f[i][j] = f[i][j - 1] + f[P[i][j - 1]][j - 1];
            g[i][j] = min(g[i][j - 1] , g[P[i][j - 1]][j - 1]);
        }
    }
    cerr << "YES";
    //cout << f[P[0][0]][0] << " " << f[P[0][1]][0];
    rep(i , 0 , n) {
        cout << lift1(i , k) << " " << lift2(i , k) << '\n';    
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test = 1; 
    //cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}
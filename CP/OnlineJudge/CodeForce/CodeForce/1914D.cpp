//source:: 
#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long
typedef unsigned __int128 ull;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int inf = 1e18 + 7;
const int N = 1e5 + 7;
const int MOD = 1e9 + 7;


void solve() {
    int n; cin >> n;
    vector<vector<int>> a(n + 1 , vector<int> (3));
    for (int i = 1 ; i <= n ;i ++) cin >> a[i][0];
    for (int i = 1 ; i <= n ;i ++) cin >> a[i][1];
    for (int i = 1 ; i <= n ;i ++) cin >> a[i][2];
    vector<vector<int>> f(n + 1 , vector<int> (1 << 3 , -1));
    f[0][0] = 0;
    for (int i = 1 ; i <= n ; i++) {
        for (int mask = 0 ; mask < (1 << 3) ; mask++) {
            f[i][mask] = f[i - 1][mask];
            for (int status = 0 ; status < 3 ; status++) {
                //cerr << mask << " " << status << '\n';
                if ((mask & (1 << status)) == (1 << status)) {
                    if (f[i - 1][mask ^ (1 << status)] != -1) {
                        f[i][mask] = max(f[i][mask] , f[i - 1][mask ^ (1 << status)] + a[i][status]);
                    }
                }
            }
        }
    }
    //cout << f[1][2];
    cout << f[n][(1 << 3) - 1] << '\n';
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test; 
    cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}
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
const int N = 2e5 + 7;
const int MOD = 998244353;

int a[N];
int f[N];   
int g[507][507];
// num of position that divide i modulo j
// sqrt(2e5) = < 500

void solve() {
    int n; cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        //g[a[i]][0] = 1;
        f[i] = 1;
    }
    for (int i = n; i >= 1 ; i--) {
        if (a[i] * a[i] >= n) {
            for (int j = i + a[i] ; j <= n ; j += a[i]) {
                f[i] = (f[i] + f[j])%MOD;
            }
        }
        else {
            f[i] = (f[i] + g[a[i]][i%a[i]])%MOD; 
        }
        for (int j = 1 ; j <= 500 ; j++) {
            g[j][i%j] = (g[j][i%j] + f[i])%MOD;
        }
    }
    int ans = 0;
    for (int i = 1 ; i <= n ;i ++) {
        ans = (ans + f[i])%MOD;
        //cout << f[i] << " ";
    }
    cout << ans%MOD;
}   

main() {
	int test = 1;
	//cin >> test;
	while(test--) {
		solve();
	}
	return 0;
}
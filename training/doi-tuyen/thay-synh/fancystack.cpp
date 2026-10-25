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
const int N = 5e3 + 7;
const int MOD = 998244353;

int C[N][N];

void calc() {
    for (int i = 0 ; i < N ; i++) C[i][i] = 1 , C[i][0] = 1;
    for (int i = 1 ; i < N ; i++) {
        for (int j = 1; j < i ; j++) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1])%MOD;
        }
    }
}

int CnK(int n , int k) {
    if (k > n) return 0; 
    return C[n][k]%MOD;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    vector<int> v;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i]; 
        if (a[i] == a[i - 1]) v.back()++;
        else v.push_back(1ll);
    } 
    if (n == 2) {
        cout << (a[2] > a[1]) << '\n';
        return;
    }
    if (a[n] == a[n - 1] || a[n - 1] == a[n - 2]) {
        cout << 0 << '\n';
        return;
    }
    vector<vector<int>> f(n + 1 , vector<int> (n + 1));
    f[0][0] = 1;
    reverse(v.begin() , v.end());
    //for (int x : v) cerr << x << " ";
    int last = 0;
    for (int i = 1 ; i <= sz(v) ; i++) {
        int cnt = v[i - 1];
        for (int j = 1 ; j <= n / 2 ; j++) {
            // add in position even
            //cerr << max(0ll , j - 2) - (last - (j - 1)) << " ";
            f[i][j] = (f[i][j] + (f[i - 1][j - 1] * CnK(max(0ll , j - 2) - (last - (j - 1)),cnt - 1)%MOD)%MOD)%MOD;
            // otherwise
            f[i][j] = (f[i][j] + (f[i - 1][j] * CnK(max(0ll , j - 1) - (last - j) + (j == n/2),cnt)%MOD)%MOD)%MOD;
        }
        last += cnt;
    }
    cout << f[sz(v)][n/2]%MOD << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    calc();
	int test = 1;
	cin >> test;
	while(test--) {
		solve();
	}
	return 0;
}
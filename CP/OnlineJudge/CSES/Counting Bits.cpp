//source:: https://cses.fi/problemset/task/1146
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
const int N = 51;
const int MOD = 1e9 + 7;

bitset<N> a;
int C[N][N];
int f[N];
int g[N];

void CnK() {
    for (int i = 0 ; i < N ; i++) 
        C[i][i] = C[i][0] = 1;
    for (int i = 1 ; i < N ; i++) {
        for (int j = 1 ; j < i ; j++) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }
}

void DP() {
    g[0] = 1;
    for (int i = 1 ; i < N ; i++) {
        for (int j = 0 ; j <= i ; j++) {
            f[i] += j*C[i][j];
            g[i] += C[i][j];
        }
    }
}

void solve() {
    int n; cin >> n;
    a = n;
    CnK();
    DP();
    int ans = 0;
    int cnt_1 = 0;
    for (int i = 50 ; i >= 0 ; i--) {
        if (a[i] == 1) {
            ans = ans + f[i] + cnt_1*g[i];
            cnt_1 ++;
        }
    }
    cout << ans + a.count();
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test = 1;
    while (test--) {
        solve();
    }
    return 0;
}
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
const int N = 1e2 + 7;
const int MOD = 1e9 + 7;

int f[N][N];

void solve() {
    int n , l; cin >> n >> l;
    vector<int> p , r , q, g;
    p = r = q = g = vector<int>(n + 1);
    repn(i , 1 , n) cin >> q[i] >> p[i] >> r[i] >> g[i];
    repn(i , 0 , n) {
        repn(j , 0 , l) {
            f[i][j] = inf;
        }
    }
    f[0][0] = 0;
    repn(i , 1 , n) {
        repn(j , 1 , l) {
            f[i][j] = f[i - 1][j];
            repn(k , 1 , min(g[i] , j)) {
                int cost = (k >= r[i] ? q[i] : p[i]); 
                f[i][j] = min(f[i][j] , f[i - 1][j - k] + k*cost);
            }
        }
    }
    repn(i , 1 , n) {
        repn(j , 1,  l) {
            cout << f[i][j] << " ";
        }
        cout << '\n';
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
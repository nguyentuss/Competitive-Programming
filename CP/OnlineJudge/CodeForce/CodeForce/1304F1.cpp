//source:: https://codeforces.com/contest/1304/problem/F1
#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int inf = 1e18 + 7;
const int N = 2e4 + 7;
const int MOD = 1e9 + 7;

// call f[i][j] is the solution when go to day i and j areas
// x thuoc (1 , j - k) maximum f[i - 1][x] + sum
// y thuoc (j + k , m - k + 1) maximum f[i - 1][y] + sum
// z thuoc (j - k + 1 , j + k - 1)


int sum[57][N];
int a[57][N];
int f[57][N];

int tt(int index , int l , int r) {
    return sum[index][r] - sum[index][l - 1];
}



main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test = 1;
    while (test--) {
        int n , m , k; cin >> n >> m >> k;
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 1 ; j <= m ; j ++) {
                cin >> a[i][j];
                sum[i][j] = sum[i][j - 1] + a[i][j];
            }
        }
        for (int j = 1 ; j + k - 1 <= m ; j++) {
            f[1][j] = tt(1 , j , j + k - 1) + tt(2 , j , j + k - 1);
        }
        for (int i = 2 ; i <= n ; i++) {
            vector<int> y(m + 2 , -1);
            vector<int> x(m + 2 , -1);
            for (int j = m - k + 1 ; j >= 1 ; j--) y[j] = max(y[j + 1] , f[i - 1][j]);
            for (int j = 1 ; j <= m - k + 1; j++) x[j] = max(x[j - 1] , f[i - 1][j]);
            for (int j = 1 ; j + k - 1 <= m ; j++) {
                int p = tt(i , j , j + k - 1) + tt(i + 1 , j , j + k - 1);
                // x
                if (j - k > 0) {
                    f[i][j] = max(f[i][j] , x[j - k] + p);
                }
                if (j + k <= m) {
                    f[i][j] = max(f[i][j] , y[j + k] + p);
                }
                for (int h = max(1LL , j - k + 1) ; h <= min(m , j + k - 1) ; h++) {
                    f[i][j] = max(f[i][j] , f[i - 1][h] + p - tt(i , max(h , j) , min(h + k - 1 , j + k - 1)));
                } 
            }
        }
        int ans = 0;
        for (int i = 1 ; i <= m ; i++) {
            ans = max(ans , f[n][i]);
        }
        cout << ans;
    }
    return 0;
}
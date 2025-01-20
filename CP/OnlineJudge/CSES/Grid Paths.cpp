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
const int N = 1e3 + 7;
const int MOD = 1e9 + 7;

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test = 1; 
    //cin >> test;
    while (test--) {
        int n; cin >> n;
        vector<vector<char>> a(n + 1 , vector<char>(n + 1));
        vector<vector<int>> f(n + 1 , vector<int> (n + 1));
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 1 ; j <= n ; j++) {
                cin >> a[i][j];
            }
        }
        f[0][1] = 1;
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 1 ; j <= n ; j++) {
                if (a[i][j] == '*') continue;; 
                (f[i][j] = f[i - 1][j] + f[i][j - 1])%=MOD;
            }
        }
        cout << f[n][n];
    }
    return 0;
}
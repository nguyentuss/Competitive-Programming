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
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int inf = 1e18 + 7;
const int N = 57;
const int MOD = 1e9 + 7;

int f[N][N];

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test = 1;
    while (test--) {
        int n , m; cin >> n >> m;
        f[1][1] = 1;
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 1 ; j <= m ; j++) {
                if (!f[i][j]) continue;; 
                if (i + 2 <= n && j + 1 <= m) f[i + 2][j + 1] += f[i][j];
                if (i + 1 <= n && j + 2 <= m) f[i + 1][j + 2] += f[i][j];
            }
        }
        cout << f[n][m];
    }
    return 0;
}
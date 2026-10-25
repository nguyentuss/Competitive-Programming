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
const int N = 20;
const int MOD = 1e9 + 7;

int f[N][N];

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test = 1;
    while (test--) {
        int n , m; cin >> n >> m;
        f[1][1] = 1; 
        for (int i = 2 ; i <= n + m ; i++) {
            for (int x = 1 ; x <= n ; x++){
                int y = i - x;
                if (!f[x][y]) continue;
                if (x + 2 <= n && y + 1 <= m) 
                    f[x + 2][y + 1] += f[x][y];
                if (x + 2 <= n && y - 1 > 0) 
                    f[x + 2][y - 1] += f[x][y]; 
                if (x + 1 <= n && y + 2 <= m) {
                    f[x + 1][y + 2] += f[x][y];
                }     
                if (x - 1 > 0 && y + 2 <= m) {
                    f[x - 1][y + 2] += f[x][y];
                }
            }
        }
        cout << f[n][m];
    }
    return 0;
}
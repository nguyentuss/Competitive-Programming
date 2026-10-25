//source:: 
#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<char , ii>
#define fi first
#define se second
#define int long long
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int inf = 1e18 + 7;
const int N = 27;
const int MOD = 1e9 + 7;

int a[N][N];
int f[N][N];
iii trace[N][N];

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test = 1;
    while (test--) {
        int n , m; cin >> n >> m;
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 1 ; j <= m ; j++) {
                cin >> a[i][j];
            }
        }
        f[1][1] = a[1][1];
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 1 ; j <= m ; j++) {
                if (i == 1 && j == 1) continue;
                if (f[i][j - 1] < f[i - 1][j]) 
                    trace[i][j] = iii('D' , ii(i - 1 , j));
                else trace[i][j] = iii('R' , ii(i , j - 1));
                f[i][j] = max(f[i][j - 1] , f[i - 1][j]) + a[i][j];
            }
        }
        cout << f[n][m] << '\n';
        int x = n , y = m;
        string s;
        while (x && y) {
            s += trace[x][y].fi; 
            x = trace[x][y].se.fi;
            y = trace[x][y].se.se;
        }
        reverse(s.begin(),s.end()); 
        for (auto x : s) {
            cout << x << " ";
        }
    }
    return 0;
}
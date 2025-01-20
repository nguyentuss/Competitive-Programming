// http://www.usaco.org/index.php?page=viewproblem2&cpid=670
#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 1e3 + 7 ;
const int MOD = 1e9 + 7;

int f[N][N][2];

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen("checklist.in","r",stdin);
    freopen("checklist.out","w",stdout);
    int n , m; cin >> n >> m;
    vector<ii> a(n + 1) , b(m + 1);
    for (int i = 1 ; i <= n ; i++) cin >> a[i].fi >> a[i].se;
    for (int i = 1 ; i <= m ; i++) cin >> b[i].fi >> b[i].se;
    function<int(ii , ii)> dist = [&](ii a , ii b) {
        return  ((a.fi - b.fi)*(a.fi - b.fi) + (a.se - b.se)*(a.se - b.se));
    };
    vector<vector<vector<int>>> f(n + 1 , vector<vector<int>> (m + 1 , vector<int>(2 , inf)));
    f[1][0][0] = 0; 
    for (int i = 1 ; i <= n ;i ++) {
        for (int j = 0 ; j <= m ; j++) {
            if (i > 1)
                f[i][j][0] = min(f[i][j][0] , f[i - 1][j][0] + dist(a[i] , a[i - 1]));
            f[i][j][0] = min(f[i][j][0] , f[i - 1][j][1] + dist(a[i] , b[j]));
            if (j > 1)
                f[i][j][1] = min(f[i][j][1] , f[i][j - 1][1] + dist(b[j] , b[j - 1]));
            if (j > 0)
            f[i][j][1] = min(f[i][j][1] , f[i][j - 1][0] + dist(a[i] , b[j]));
        }
    }
    cout << f[n][m][0];

    return 0;
} 
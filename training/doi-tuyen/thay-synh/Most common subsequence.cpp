#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ii pair<int , int>
#define sz(x) (int)x.size()

const int N = 1e3 + 7;
const int inf = 1e18;

int f[N][N];
int a[N] , b[N];

main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    int m; cin >> m; 
    for (int i = 1 ; i <= m ; i++) cin >> b[i];
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            f[i][j] = max(f[i][j - 1] , f[i - 1][j]);
            if (a[i] == b[j]) {
                f[i][j] = max(f[i][j] , f[i - 1][j - 1] + 1);
            }
        }
    }
    cout << f[n][m];
    return 0;
}
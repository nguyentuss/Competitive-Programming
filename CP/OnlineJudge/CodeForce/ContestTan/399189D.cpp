#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 1e5 + 7;
const int MOD = 1e9 + 7;

int f[N][10][2];
int a[N];

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for (int i = 1 ; i <= n ;i ++) {
        cin >> a[i];
    }
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 0 ; j < 10 ;j ++) {
            for (int status = 0 ; status <= 1 ; status++) {
                f[i][j][status]= inf;
            }
        }
    }
    f[0][0][1] = 0;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 0 ; j <= min(i , 9ll) ; j++) {
            // chọn ô đó để đóng
            if (j) f[i][j][1] = min(f[i - 1][j - 1][0] , f[i - 1][j - 1][1]) + a[i];
            // không chọn để trống
            int sum = 0 , mini = inf;
            for (int k = i ; k >= max(1ll , i - 10 + 1) ; k--) {
                sum += a[k];
                mini = min(mini , a[k]);
                int cc = 0;
                if (k == (i - 10 + 1)) cc = mini;
                f[i][j][0] = min(f[i][j][0] , min(f[k - 1][j][1] , f[k - 1][j][0]) + sum - cc);
            }

        }
    }
    int ans = inf;
    for (int i = 0 ; i < 10 ; i++) {
        ans = min({ans , f[n][i][0] , f[n][i][1]});
    }
    cout << ans;    
    return 0;
}
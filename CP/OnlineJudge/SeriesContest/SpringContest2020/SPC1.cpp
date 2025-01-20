#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>


#pragma GCC optimize("Ofast")
#define MAX_M (int) (2e3 + 7)
#define MAX_N (int) (2e6 + 7)
#define inf (int) (2e6 + 7)

using namespace std;

vector <int> a(MAX_N);
vector <int> b(MAX_M);
vector <int> v[2007];
int m , n , x;
int dp[MAX_M][MAX_M];

void init() {
    for (int i = 1 ; i <= 2000 ; i++) v[i].clear();
    for (int i = 0 ; i <= n; i++) 
        for (int j = 0 ; j <= n; j++) 
            dp[i][j] = inf;
}


int main(){

    int T; cin >> T;
    for (int test = 0 ; test < T ; test ++) {
        cin >> m >> n;
        init();
        for (int i = 1 ; i <= m ; i++) 
            cin >> a[i];
        for (int i = 1 ; i <= n ; i++) 
            cin >> b[i];
        for (int i = 1 ; i <= m ; i++) 
            v[a[i]].push_back(i);
        for (int i = 0 ; i <= n ; i++) 
            dp[i][0] = 0;
        for (int i = 0 ; i < n; i++) { 
            for (int j = 0 ; j <= n ; j++) {
                if (dp[i][j] != inf) {
                    //cout << i << " " << j << " : " << dp[i][j] << endl;
                    dp[i + 1][j] = min(dp[i + 1][j] , dp[i][j]);
                    int l = 0 , r = (int) v[b[i +1]].size() - 1, pos = inf;
                    //cout << a[i+1] << " " << l << " " << r << endl;
                    while (l <= r) {
                        //cout << "HELLO" << endl;
                        int mid = (l + r)/2;
                        if (v[b[i + 1]][mid] > dp[i][j]) {
                            pos = min(pos , v[b[i + 1]][mid]);
                            r = mid - 1;
                        }
                        else l = mid + 1;
                    }
                    //cout << pos << endl;
                    dp[i + 1][j + 1] = min(dp[i+1][j+1],pos);
                }
            }
        }
        int ans = 0;
        for (int j = 0 ; j <= n ; j++) 
        if (dp[n][j] <= m) ans = max(ans , j);
        cout << ans << endl;  
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ii pair<int , int>
#define sz(x) (int)x.size()

const int N = 1e3 + 7;
const int inf = 1e18;

int f[N][N];

main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);   
    string A; cin >> A;
    string B; cin >> B;
    int n = A.size() , m = B.size();
    for (int i = 0 ; i <= n ; i++) {
        for (int j = 0 ; j <= m ; j++) {
            f[i][j] = inf;
        }
    }
    for (int i = 0 ; i <= n ; i++) 
        f[i][0] = i;
    for (int i = 0 ; i <= m ; i++) {
        f[0][i] = i;
    }
    A = " " + A; B = " " + B;
    for (int i = 1 ; i <= n ; i ++) {
        for (int j = 1 ; j <= m ; j++) {
            if (A[i] == B[j]) {
                f[i][j] = f[i - 1][j - 1];
            }
            else {
                f[i][j] = 1 + min({f[i - 1][j] , f[i][j - 1] , f[i - 1][j - 1]});
            }
        }
    }
    cout << f[n][m];
    return 0;
}
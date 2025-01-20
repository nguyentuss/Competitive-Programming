#include <bits/stdc++.h>

using namespace std;

const int N = 507;

int f[N][N];

/*
 |      |       |
 |      |       |
 |- - - |- -- - |
 |      |       |
*/


int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < N ; j++) {
            f[i][j] = 1e9;
        }
    }
    int n , m; cin >> n >> m;
    for (int i = 0 ; i <= n ; i++) {
        for (int j = 0 ; j <= m ; j++) {
            if (i == j) {
                f[i][j] = 0;
                continue;
            }
            for (int k = 1 ; k < i ; k++) {
                f[i][j] = min(f[i][j] , f[k][j] + f[i - k][j] + 1);     
            }
            for (int k = 1 ; k < j ; k++) {
                f[i][j] = min(f[i][j] , f[i][k] + f[i][j - k] + 1);
            }
        }
    }
    cout << f[n][m];
    return 0;
}
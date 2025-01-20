#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 507;
const int MOD = 1e9 + 7;

int f[N][N*(N + 1)/2];

int pow(int n) {
    if (n == 1) return 2;
    int child = pow(n/2)%MOD;
    if (n % 2 == 0) return (child*child)%MOD;
    else return ((child*child)%MOD*2)%MOD;
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for (int i = 0 ; i < N ; i++) f[i][0] = 1;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 0 ; j <= n * (n + 1)/2 ; j++) {
            if (j < i) {
                f[i][j] = f[i - 1][j]%MOD;
            }
            else f[i][j] = (f[i - 1][j - i]%MOD + f[i - 1][j]%MOD)%MOD;
        }
    }
    int X = n * (n + 1)/2; 
    if (X % 2 != 0) cout << 0;
    else {
        cout << f[n][X/2]*pow(MOD - 2)%MOD;
    }
    return 0;
}
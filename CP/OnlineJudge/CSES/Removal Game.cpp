#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 7;
#define int long long

int f[N][N];
int a[N];

main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    int sum = 0;; 
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        f[i][i] = a[i];
        sum += a[i];
    }
    for (int r = 1 ; r <= n ; r++) {
        for (int l = r - 1 ; l >= 1 ; l--) {
            f[l][r] = max(a[l] - f[l + 1][r] , a[r] - f[l][r - 1]);
        }
    }
    cout << (sum + f[1][n])/2;

    return 0;
}
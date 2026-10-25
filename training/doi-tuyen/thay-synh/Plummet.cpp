#include <bits/stdc++.h>

using namespace std;

int f[107][107 * 107];

int main() {
    int n; cin >> n;
    vector<int> a(n + 1);
    int sum = 0;
    for (int i = 1 ; i <= n ; i++) cin >> a[i] , sum += a[i];
    f[0][0] = 1;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1; j <= sum ; j++) {
            f[i][j] = max(f[i][j] , f[i - 1][j]);
            if (j - a[i] >= 0 && f[i - 1][j - a[i]] == 1) {
                f[i][j] = 1;
            }
        }
    } 
    if (sum % 2 == 0) {
        if (f[n][sum] && f[n][sum / 2]) {
            cout << "YES";
        }
    }
    else cout << "NO";
    return 0;
}
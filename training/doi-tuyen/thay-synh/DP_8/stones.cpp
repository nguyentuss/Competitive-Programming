#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e3 + 7;

bool f[N];

bool checked(int i , int j) {
    return (i - j >= 0 && !f[i - j]);
}

void solved() {
    int n; cin >> n;
    f[0] = false;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= 3 ; j++) {
            if (j == 1 && checked(i , j)) {
                f[i] = true;
            }
            if (j == 2 && checked(i , j) && (i % 3 == 0 || i % 3 == 2)) {
                f[i] = true;
            }
            if (j == 3 && checked(i , j) && (i % 3 == 1 || i % 3 == 2)) {
                f[i] = true;
            }
        }
    }
    cout << (f[n] ? 1 : 2);
    return;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    solved();
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (107)
#define inf (int) (1e9 + 7)

int trace[MAX_N][1 << 17];
int a[MAX_N];
int f[MAX_N][1 << 17];
int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
int msk[60];


int main() {
    ios::sync_with_stdio(0);cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    for (int i = 1 ; i <= n ;i++)  {
        cin >> a[i];
    }
    for (int i = 2 ; i < 60 ; i++) {
        for (int j = 0 ; j < 17 ; j++) {
            if (i % prime[j] == 0) {
                msk[i] |= (1 << j);
            }
        }
    }
    for (int i = 1 ; i <= n ; i++){
        for (int mask = 0 ; mask < (1 << 17) ; mask++) {
            f[i][mask] = inf;
        }
    }
    f[0][0] = 0;
    for (int i = 0 ; i < n ; i++) {
        for (int mask = 0 ; mask < (1 << 17) ; mask++) {
            if (f[i][mask] == inf) continue;
            if (f[i + 1][mask] > (f[i][mask] + a[i + 1] - 1)) {
                f[i + 1][mask] = f[i][mask] + a[i + 1] - 1;
                trace[i + 1][mask] = 1;
            }
            for (int x = 1 ; x < 60 ; x++) {
                if (mask & msk[x]) continue;
                if (f[i + 1][mask | msk[x]] > (f[i][mask] + abs(a[i + 1] - x))) {
                    f[i + 1][mask | msk[x]] = f[i][mask] + abs(a[i + 1] - x);
                    trace[i + 1][mask | msk[x]] = x;
                }
            }
        }
    }
    int ans = inf;
    int mask = 0;
    for (int i = 0 ; i < (1 << 17) ; i++) {
        if (ans > f[n][i]) {
            ans = f[n][i];
            mask = i;
        }
    }
    //cout << trace[n][mask];
    vector<int> v;
    int x = n;
    while (x > 0) {
        v.push_back(trace[x][mask]);
        mask ^= msk[trace[x][mask]];
        x--;
    }
    reverse(v.begin() , v.end());
    for (auto x : v) cout << x << " ";
    return 0;
}


// 1231 
// 
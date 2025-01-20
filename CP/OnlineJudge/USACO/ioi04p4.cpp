// https://dmoj.ca/problem/ioi04p4

#include <bits/stdc++.h>

using namespace std;

struct arr {
    int w , h;
};

arr a[207];

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    int W , H; cin >> W >> H;
    int n; cin >> n;
    vector<vector<int>> f;
    f.resize(H + 1 , vector<int> (W + 1 , 0));
    // goi f[i][j] la cach xep 1 matrix i*j sao cho dap an bai toan la min
    for (int i = 1 ; i <= H ; i++) {
        for (int j = 1 ; j <= W ; j++) {
            f[i][j] = i*j;
        }
    }
    for (int i = 1 ; i <= n ;i ++) {
        cin >> a[i].w >> a[i].h;
        f[a[i].h][a[i].w] = 0;
    }   
    for (int i = 1 ; i <= H ; i++) {
        for (int j = 1 ; j <= W ; j++) {
            for (int x = 1 ; x <= i ; x++) {
                f[i][j] = min(f[i][j] , f[x][j] + f[i - x][j]);
            }
            for (int y = 1 ; y <= j ; y++) {
                f[i][j] = min(f[i][j] , f[i][y] + f[i][j - y]);
            }
        }
    }
    cout << f[H][W];
    return 0;
}
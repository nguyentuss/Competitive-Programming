#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (307)

struct arr {
    int len;
    char l , r;
};

int n , L;
arr a[MAX_N];
int g[MAX_N][MAX_N][2][2];
int f[MAX_N][MAX_N][MAX_N];

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> L;
    for (int i = 1 ; i <= n ;i ++) {
        cin >> a[i].len >> a[i].l >> a[i].r;
        if (a[i].r == 'in') a[i].r = 'out';
        if (a[i].r == 'out') a[i].r = 'in';
    }
    f[0][0][0][0] = 1;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j <= L ; j ++) {
            for (int haveIn = 0 ; haveIn <= 1 ; haveIn++) {
                for (int haveOut = 0 ; haveOut <= 1 ; haveOut++) {
                    if (f[i][j][haveIn][haveOut]) {
                        f[i + 1][j][haveIn][haveOUt] += f[i][j][haveIn][haveOut];
                        if (a[i + 1].r ==   )
                    }
                }
            }
        }
    }


    return 0;
}
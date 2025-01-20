#include <bits/stdc++.h>

using namespace std;

#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define int long long

const int MOD = 1e9 + 7;
const int MAX_N = 1e5 + 7;

int f[MAX_N][4];
// status = 0 : tat ca deu la A[i] = B[i]
// status = 1 : vua co A[i] = B[i] va A[i] > B[i] 
// status = 2 : vua co A[i] = B[i] va A[i] < B[i]
// status = 3 : vua co A[i] = B[i] va A[i] > B[i] va A[i] < B[i]

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    string A , B; cin >> A >> B;
    A = " " + A;
    B = " " + B;
    f[0][0] = 1;
    for (int i = 1 ; i <= n ; i++) {
        if (A[i] == '?' && B[i] == '?') {
            f[i][0] = (f[i - 1][0]*10)%MOD;
            f[i][1] = (f[i - 1][1]*55 + f[i - 1][0]*45)%MOD;
            f[i][2] = (f[i - 1][2]*55 + f[i - 1][0]*45)%MOD;
            f[i][3] = (f[i - 1][3]*100 + (f[i - 1][1] + f[i - 1][2])*45)%MOD;
        }
        else if (A[i] == '?' && B[i] != '?') {
            f[i][0] = f[i - 1][0];
            f[i][1] = (f[i - 1][1]*('9' - B[i] + 1) + f[i - 1][0]*('9' - B[i]))%MOD;
            f[i][2] = (f[i - 1][2]*(B[i] - '0' + 1) + f[i - 1][0]*(B[i] - '0'))%MOD;
            f[i][3] = (f[i - 1][3]*10 + f[i - 1][1]*(B[i] - '0') + f[i - 1][2]*('9' - B[i]))%MOD;
        }
        else if (A[i] != '?' && B[i] == '?') {
            f[i][0] = f[i - 1][0];
            f[i][1] = (f[i - 1][1]*(A[i] - '0' + 1) + f[i - 1][0]*(A[i] - '0'))%MOD;
            f[i][2] = (f[i - 1][2]*('9' - A[i] + 1) + f[i - 1][0]*('9' - A[i]))%MOD;
            f[i][3] = (f[i - 1][3]*10 + f[i - 1][1]*('9' - A[i]) + f[i - 1][2]*(A[i] - '0'))%MOD;
        }
        else if (A[i] != '?' && B[i] != '?') {
            if (A[i] < B[i]) {
                f[i][2] = (f[i - 1][2] + f[i - 1][0])%MOD;
                f[i][3] = (f[i - 1][3] + f[i - 1][1])%MOD;
            }
            else if (A[i] > B[i]) {
                f[i][1] = (f[i - 1][1] + f[i - 1][0])%MOD;
                f[i][3] = (f[i - 1][3] + f[i - 1][2])%MOD;
            }
            else {
                f[i][0] = f[i - 1][0];
                f[i][1] = f[i - 1][1];
                f[i][2] = f[i - 1][2];
                f[i][3] = f[i - 1][3];
            }
        }
    }
    for (int i = 1 ; i <= n ;i ++) {
        for (int status = 0 ; status <= 3 ; status ++) {
            cerr << f[i][status] << " ";
        }
        cerr << '\n';
    }
    cout << f[n][3];
    return 0;
}
// status = 0 : tat ca deu la A[i] = B[i]
// status = 1 : vua co A[i] = B[i] va A[i] > B[i] 
// status = 2 : vua co A[i] = B[i] va A[i] < B[i]
// status = 3 : vua co A[i] = B[i] va A[i] > B[i] va A[i] < B[i]
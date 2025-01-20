#include <bits/stdc++.h>

using namespace std;

#define int long long

int f[20][177][3];
vector<int> v;
int pos[1 << 9];

int calc(int n) {
    memset(f , 0 , sizeof f);
    string N; int x = n;
    while (x > 0) {
        N += to_string(x % 10);
        x /= 10;
    }    
    reverse(N.begin() , N.end());
   // cerr << N << '\n';
    for (int num = 1 ; num <= 9 ; num++) {
        int status;
        if (num > N[0] - '0') status = 2;
        if (num == N[0] - '0') status = 1;
        if (num < N[0] - '0') status = 0;
        f[1][1][status] ++;
    }
    for (int i = 1 ; i < N.size() ; i++) {
        for (int j = 1 ; j <= 3 ; j++) {
            for (int status = 0 ; status <= 2 ; status ++) {
                if (!f[i][j][status]) continue;
                for (int num = 0 ; num <= 9; num ++) {
                    if (num == 0) {
                        int nstatus = status;
                        if (nstatus == 1) {
                            if (num < N[i] - '0') nstatus = 0;
                            if (num > N[i] - '0') nstatus = 2;
                        }
                        f[i + 1][j][nstatus] += f[i][j][status];
                    }
                    else {
                        int newj = j + 1;
                        if (newj > 3) continue;  
                        int nstatus = status;
                        if (nstatus == 1) {
                            if (num < N[i] - '0') nstatus = 0;
                            if (num > N[i] - '0') nstatus = 2;
                        }
                        f[i + 1][newj][nstatus] += f[i][j][status];
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1 ; i <= N.size() ; i++) {
        for (int j = 1 ; j <= 3 ; j++) {
            for (int status = 0 ; status <= (i == N.size() ? 1 : 2) ; status++) {
                ans += f[i][j][status]; 
            }
        }
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    int q; cin >> q;
    for (int i = 1 ; i <= q ; i++) {
        int a , b; cin >> a >> b;
        cout << calc(b) - calc(a - 1) << '\n';
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define ll long long

string N;
ll f[20][20][9][3];

void init() {
    for (int i = 0 ; i <= 19 ; i++) {
            for (int num = 0 ; num <= 19 ; num++) {
                for (int r = 0 ; r <= 8 ; r ++) {
                    for (int status = 0 ; status <= 2 ; status ++) {
                        f[i][num][r][status] = 0LL;
                }
            }
        }
    }
}

ll dynamicProgramming() {
    init();
    int len = N.size();
    for (int num = 1 ; num <= 9 ; num++) {
        int status;
        if (num < N[0] - '0') status = 0;
        else if (num == N[0] - '0') status = 1;
        else status = 2;
        f[1][num == 6 || num == 8][num%8][status] ++;
    }
    for (int i = 1 ; i < len ; i ++) {
        for (int cnt = 0 ; cnt <= 19 ; cnt++) {
            for (int r = 0 ; r <= 8 ; r ++) {
                for (int status = 0 ; status <= 2 ; status++) {
                    if (f[i][cnt][r][status] == 0) continue;
                    ll val = f[i][cnt][r][status];
                    for (int num = 0 ; num <= 9 ; num++) {
                        int newstatus = status;
                        int newcnt = cnt + (num == 6 || num == 8);
                        int newr = (r*10 + num)%8;
                        if (newstatus == 1) {
                            if (num < N[i] - '0') newstatus = 0;
                            else if (num > N[i] - '0') newstatus = 2;
                        }
                        f[i + 1][newcnt][newr][newstatus] += val;
                    }
                }
            }
        }
    }
    //cout << f[2][1][0][0];
    ll res = 0;
    for (int i = 1 ; i <= len ; i++) {
        for (int cnt = 1 ; cnt <= 19 ; cnt ++){
            for (int status = 0 ; status <= (i < len ? 2 : 1) ; status++) {
                res += cnt*f[i][cnt][0][status];
            }
        }
    }
    ll tmp = atoi(N.c_str());
    if (tmp % 8 != 0) {
        for (auto e : N) {
            if (e == '6' || e == '8') {
                res ++; 
            }
        }
    }
    return 1LL*res;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        cin >> N;
        cout << dynamicProgramming() << '\n';
    }
    return 0;
}
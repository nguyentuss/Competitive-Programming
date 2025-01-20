#include <bits/stdc++.h>

using namespace std;

#define int long long
const int MAX_N = 1e2 + 7;
const int inf = 1e9 + 7; 
const int MOD = 1e9 + 7;
const int MM = 8;

// 2 , 3 , 5 , 7 , 11 , 13 , 17 , 19 
// lim(x) 2^x = 8
// lim(x) 3^x = 5
// lim(x) 5^x = 3
// lim(x) 7^x = 3
// lim(x) 11^x = 2
// lim(x) 13^x = 2
// lim(x) 17^x = 2
// lim(x) 19^x = 2

struct save {
    int x;
    vector<int> pw;
    int rest = 1;   
};
int f[2][9][6][4][4][3][3][3][3][2];
int pos[20];

int POW(int base , int m) {
    int total = 1;
    for (int i = 1 ; i <= m ; i++) total *= base;
    return total;
}

void init(int now) {
    for (int p2 = 0 ; p2 <= 8 ; p2 ++) {
        for (int p3 = 0 ; p3 <= 5 ; p3++) {
            for (int p5 = 0 ; p5 <= 3 ; p5++) {
                for (int p7 = 0 ; p7 <= 3 ; p7++) {
                    for (int p11 = 0 ; p11 <= 2 ; p11++) {
                        for (int p13 = 0 ; p13 <= 2 ; p13++) {
                            for (int p17 = 0 ; p17 <= 2 ; p17++) {
                                for (int p19 = 0 ; p19 <= 2 ; p19++) {
                                    for (int have = 0 ; have <= 1 ; have++) {
                                        f[now][p2][p3][p5][p7][p11][p13][p17][p19][have] = 0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

bool cmp(save &a , save &b) {
    return a.rest < b.rest;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    pos[2] = 0 , pos[3] = 1 , pos[5] = 2 , pos[7] = 3 , pos[11] = 4 , pos[13] = 5 , pos[17] = 6 , pos[19] = 7;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<save> rpl(n + 1);
        for (int i = 1 ; i <= n ; i++) 
            cin >> rpl[i].x;
        rpl[0].pw.assign(8 , 0);
        for (int i = 1 ; i <= n ; i++) {
            rpl[i].pw.assign(8 , 0); 
            int tmp = rpl[i].x;
            for (int x = 2 ; x*x <= tmp ; x++) {
                if (tmp % x == 0) {
                    int cnt = 0;
                    while (tmp % x == 0) {
                        cnt++;
                        tmp /= x;
                    }
                    if (x <= 19) {
                        rpl[i].pw[pos[x]] = cnt;
                    }
                }
            }
            if (tmp > 1 && tmp > 19) rpl[i].rest = tmp;
            else if (tmp > 1 && tmp <= 19) rpl[i].pw[pos[tmp]]++;
        }
        sort(rpl.begin() + 1 , rpl.begin() + 1 + n , cmp);
        memset(f , 0 , sizeof f); 
        f[0][0][0][0][0][0][0][0][0][0] = 1;
        for (int i = 0 ; i < n ; i++) {
            int now = i & 1;
            int nxt = now ^ 1;
            for (int p2 = 0 ; p2 <= 8 ; p2 ++) {
                for (int p3 = 0 ; p3 <= 5 ; p3++) {
                    for (int p5 = 0 ; p5 <= 3 ; p5++) {
                        for (int p7 = 0 ; p7 <= 3 ; p7++) {
                            for (int p11 = 0 ; p11 <= 2 ; p11++) {
                                for (int p13 = 0 ; p13 <= 2 ; p13++) {
                                    for (int p17 = 0 ; p17 <= 2 ; p17++) {
                                        for (int p19 = 0 ; p19 <= 2 ; p19++) {
                                            for (int have = 0 ; have <= 1 ; have++) {
                                                if (f[now][p2][p3][p5][p7][p11][p13][p17][p19][have] == 0) continue;  
                                                int np2 = max(p2 , rpl[i + 1].pw[0]);
                                                int np3 = max(p3 , rpl[i + 1].pw[1]);
                                                int np5 = max(p5 , rpl[i + 1].pw[2]);
                                                int np7 = max(p7 , rpl[i + 1].pw[3]);
                                                int np11 = max(p11 , rpl[i + 1].pw[4]);
                                                int np13 = max(p13 , rpl[i + 1].pw[5]);
                                                int np17 = max(p17 , rpl[i + 1].pw[6]);
                                                int np19 = max(p19 , rpl[i + 1].pw[7]); 
                                                // bo qua so i + 1
                                                if (rpl[i].rest != rpl[i + 1].rest) {
                                                    (f[nxt][p2][p3][p5][p7][p11][p13][p17][p19][0] += f[now][p2][p3][p5][p7][p11][p13][p17][p19][have]%MOD)%=MOD;
                                                }
                                                else (f[nxt][p2][p3][p5][p7][p11][p13][p17][p19][have] += f[now][p2][p3][p5][p7][p11][p13][p17][p19][have]%MOD)%=MOD;
                                                // neu chon i + 1
                                                if (have == 0 || (have == 1 && rpl[i].rest != rpl[i + 1].rest)) {
                                                    f[nxt][np2][np3][np5][np7][np11][np13][np17][np19][1] = (f[nxt][np2][np3][np5][np7][np11][np13][np17][np19][1] + rpl[i + 1].rest%MOD*f[now][p2][p3][p5][p7][p11][p13][p17][p19][have]%MOD)%MOD;
                                                }
                                                else (f[nxt][np2][np3][np5][np7][np11][np13][np17][np19][1] += f[now][p2][p3][p5][p7][p11][p13][p17][p19][have])%=MOD;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            init(now);
        }
        int ans = 0;
        for (int p2 = 0 ; p2 <= 8 ; p2 ++) {
            for (int p3 = 0 ; p3 <= 5 ; p3++) {
                for (int p5 = 0 ; p5 <= 3 ; p5++) {
                    for (int p7 = 0 ; p7 <= 3 ; p7++) {
                        for (int p11 = 0 ; p11 <= 2 ; p11++) {
                            for (int p13 = 0 ; p13 <= 2 ; p13++) {
                                for (int p17 = 0 ; p17 <= 2 ; p17++) {
                                    for (int p19 = 0 ; p19 <= 2 ; p19++) {
                                        for (int have = 0 ; have <= 1 ; have++) {
                                            ans = (ans + f[n & 1][p2][p3][p5][p7][p11][p13][p17][p19][have]%MOD*POW(2LL , p2)%MOD*POW(3ll , p3)%MOD*POW(5ll , p5)%MOD*POW(7ll , p7)%MOD* 
                                            POW(11ll , p11)%MOD*POW(13ll , p13)%MOD*POW(17ll , p17)%MOD*POW(19ll , p19)%MOD)%MOD;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << ans - 1 << "\n";
    }
    return 0;
}
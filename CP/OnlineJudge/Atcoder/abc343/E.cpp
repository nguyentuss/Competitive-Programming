//
// Created by tuloc on 3/24/2024.
//
#include <bits/stdc++.h>

using namespace std;

#define int long long

// V3 > 0 phai giao giua 3 thang
// V2 > 0 phai giao giua 2 thang hoac 3 thang

int f(int a1 , int b1 , int c1 , int a2 , int b2 , int c2 , int a3 , int b3 , int c3) {
    int res = 1;
    res *= max(0ll , min({a1 , a2 , a3}) + 7 - max({a1,a2,a3}));
    res *= max(0ll , min({b1 , b2 , b3}) + 7 - max({b1,b2,b3}));
    res *= max(0ll , min({c1 , c2 , c3}) + 7 - max({c1,c2,c3}));
    return res;
}

int f(int a2 , int b2 , int c2 , int a3 , int b3 , int c3) {
    int res = 1;
    res *= max(0ll , min({a2 , a3}) + 7 - max({a2,a3}));
    res *= max(0ll , min({b2 , b3}) + 7 - max({b2,b3}));
    res *= max(0ll , min({c2 , c3}) + 7 - max({c2,c3}));
    return res;
}

void solve() {
    int V1 , V2 , V3; cin >> V1 >> V2 >> V3;
    int a1 = 0 , b1 = 0 , c1 = 0;
    for (int a2 = -7 ; a2 <= 7 ; a2++) {
        for (int b2 = -7 ; b2 <= 7 ; b2++) {
            for (int c2 = -7 ; c2 <= 7 ; c2++) {
                for (int a3 = -7 ; a3 <= 7 ; a3++) {
                    for (int b3 = -7 ; b3 <= 7 ; b3++) {
                        for (int c3 = -7 ; c3 <= 7 ; c3++) {
                            int nv3 = f(0, 0, 0, a2, b2, c2, a3, b3, c3);
                            int nv2 = f(0, 0, 0, a2, b2, c2) + f(0, 0, 0, a3, b3, c3) + f(a2, b2, c2, a3, b3, c3) -
                                      nv3 * 3;
                            int nv1 = 3 * 7 * 7 * 7 - nv2 * 2 - nv3 * 3;
                            if (V1 != nv1 or V2 != nv2 or V3 != nv3) continue;
                                cout << "Yes\n" << 0 << " " << 0 << " " << 0 << " " << a2 << " " << b2 << " " << c2 << " " << a3 << " " << b3 << " " << c3 << '\n';
                            return;
                        }
                    }
                }
            }
        }
    }
    cout << "No";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
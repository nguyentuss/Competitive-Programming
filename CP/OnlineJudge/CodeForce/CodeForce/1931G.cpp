//source:: 
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int inf = 1e18 + 7;
const int N = 2e6 + 7;
const int MOD = 998244353;

// C(n , k) = n!/(n - k)!*k!

int pw[N];

int pow(int a , int n) {
    int ret = 1;

    //12 = 1100
    //ret = a^12, a = a^8
    while (n) {
        if (n & 1) {
            ret = (ret * a) % MOD;
        }
        a = (a * a) % MOD; // a^(2^i)
        n >>= 1;
    }

    return ret%MOD;
}

void init() {
    pw[1] = 1;
    pw[0] = 1;
    for (int i = 2 ; i < N ; i++) {
        pw[i] = (pw[i - 1] * i)%MOD;
    }

}

int CnK(int n , int k) {
    int res = pw[n];
    res = (res * pow(pw[n - k] , MOD - 2))%MOD;
    res = (res * pow(pw[k] , MOD - 2))%MOD;
    return res;
}

void solve() {
    int c1 , c2 , c3 , c4; 
    cin >> c1 >> c2 >> c3 >> c4; 
    if (c1 + c2 == 0) {
        if (c3 + c4 == 0) {
            cout << 1 << '\n';
            return;
        }
        if (c3 && !c4) {
            cout << 1 << '\n';
            return;
        }
        if (c4 && !c3) {
            cout << 1 << '\n';
            return;
        }
        cout << 0 << '\n'; 
        return;
    }
    if (abs(c1 - c2) > 1) {
        cout << 0 << '\n';
        return;
    }
    // chia keo euler : https://viblo.asia/p/bai-toan-chia-keo-euler-L4x5xqvqKBM
    int m = max(c1 , c2);
    if (c1 != c2) {
        cout << (CnK(c3 + m - 1 , m - 1) * CnK(c4 + m - 1 , m - 1))%MOD << '\n';
    }
    else {
        cout << ((CnK(c3 + c1 , m)*CnK(c4 + c2 - 1 , m - 1)%MOD)%MOD + (CnK(c3 + c1 - 1 , m - 1)*CnK(c4 + c2 , m)%MOD)%MOD)%MOD << '\n';
    }
    return;
}

main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); 
	cout.tie(NULL);
	int test = 1;
	cin >> test;
    init();
	while(test--) {
		solve();
	}
	return 0;
}
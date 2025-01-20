//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

/**
 * Author: Noam527
 * Date: 2019-04-24
 * License: CC0
 * Source: folklore
 * Description:
 * Status: tested
 */
#pragma once

const ll mod = 1000000007; // faster if const
const int N = 2e5 + 7;

int fact[N]; 
int inv_fact[N];

ll modpow(ll b, ll e) {
	ll ans = 1;
	for (; e; b = b * b % mod, e /= 2)
		if (e & 1) ans = ans * b % mod;
	return ans%mod;
}

int C(int n , int k) {
    if (k > n) return 0;
    if (k < 0 || n < 0) return 0;
	return ((fact[n] * inv_fact[k])%mod*inv_fact[n - k] )%mod;
}

void solve() {
    int n; cin >> n;
    int ans = 0;
    //cout << C(7 , 3) << '\n';
    for (int sz = 0 ; sz <= n ; sz++) {
        int total = 0;
        for (int num = sz + 1 ; num <= sz + n + 1 ; num++) {
            ans = (ans + ((num * C(min(n , num - 1) , num - sz - 1))%mod * C(max(0ll , n - num), 2 * sz - num + 1))%mod)%mod;
            //(total += num * C(min(n , num - 1) , num - sz - 1) * C(max(0ll , n - num), 2 * sz - num + 1))%=mod;
            //cerr << num << " " << min(n , num) << " " << num - sz - 1 << " " << max(0ll , n - num) << " " << 2 * sz - num + 1 << " " <<  num * C(min(n , num + 1) , num - sz - 1) * C(max(0ll , n - num), 2 * sz - num + 1) << '\n'; 
        }
        //cerr << total << '\n';
    }
    cout << ans%mod << '\n';
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
	fact[0] = 1;
	for (int i = 1 ; i < N ; i++) fact[i] = (i * fact[i - 1])%mod;
    for (int i = 0 ; i < N ; i++) inv_fact[i] = modpow(fact[i] , mod - 2);
    cin >> test;
    while (test--) {
        solve();
    }
}
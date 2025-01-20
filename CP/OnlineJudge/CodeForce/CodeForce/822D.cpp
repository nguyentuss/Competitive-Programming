//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define le(x) (x << 1ll)
#define ri(x) ((x << 1ll) + 1)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int inf = 1e9;
const int mod = 1e9 + 7;

/**
 * Author: Håkan Terelius
 * Date: 2009-08-26
 * License: CC0
 * Source: http://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
 * Description: Prime sieve for generating all primes up to a certain limit. isprime$[i]$ is true iff $i$ is a prime.
 * Status: Tested
 * Time: lim=100'000'000 $\approx$ 0.8 s. Runs 30\% faster if only odd indices are stored.
 */
#pragma once

const int MAX_PR = 5'000'009;
vector<int> isprime(MAX_PR);
void eratosthenesSieve(int lim) {
	for (int i = 4; i < lim; i += 2) isprime[i] = 2;
	for (int i = 3; i < lim; i += 2) {
        if (!isprime[i]) {
		    for (int j = i*i; j < lim; j += i*2) if(!isprime[j]) isprime[j] = i;
        }
    }
    for (int i = 2 ; i < lim ; i++) if (!isprime[i]) isprime[i] = i;
}

int power(int a , int b) {
    if (b == 0) return 1;
    int child = power(a , b/2)%mod;
    return ((child*child%mod)%mod*(b&1?a:1))%mod;
}

int mul(int a , int b) {
    return (a*b)%mod;
}

void solve() {
    eratosthenesSieve(5E6 + 7); 
    int t , l , r; cin >> t >> l >> r;
    vector<int> f(r + 1);
    f[2] = 1; 
    f[1] = 0;
    vector<int> cnt(5E6 + 7 , 1);
    vector<int> sum(r + 1);
    sum[1] = f[1]; 
    sum[2] = (t*f[2])%mod;
    int p2 = power(2 , mod - 2)%mod;
    vector<int> powt(r + 1);
    powt[0] = 1; 
    for (int i = 1 ; i <= r ; i++) {
        powt[i] = (powt[i - 1] * t)%mod;
    }
    // vector<int> g(120 , inf);
    // g[2] = 1;
    // g[1] = 0;
    // for (int i = 3 ; i <= 105 ; i++) {
    //     g[i] = i*(i - 1)/2;
    //     for (int j = 2 ; j < i*i ; j++) {
    //         if (i % j == 0) {
    //             g[i] = min(g[i] , g[j] + j*(i/j)*(i/j - 1)/2);
    //         }
    //     }
    //     cout << i << " " << g[i] << '\n';
    // }
    
    for (int i = 3 ; i <= r ; i++) {
        assert(isprime[i] > 0);
        int m = (i/isprime[i])%mod;
        assert(m > 0);
        int vcl = power(m , mod - 2)%mod;
        f[i] = (f[m] + (m*(i/m)*(i/m-1)/2)%mod)%mod;
        // f[i] = (f[m] + (m*(i/m)*(i/m-1)/2));
    }   
    cout << f[13608] << '\n';
    int ans = 0; 
    int p = 1;
    for (int i = l ; i <= r ; i++) {
        ans = (ans + p*f[i])%mod;
        (p *= t)%=mod;
    }
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    // cin >> test;
    while (test--) {
        solve();
    }
 
}

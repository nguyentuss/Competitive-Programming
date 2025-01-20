//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define int long long	
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int inf = 1e18 + 7;
const int N = 1e6 + 7;
const int MOD = 1e18 + 7;

/**
 * Author: Håkan Terelius
 * Date: 2009-08-26
 * License: CC0
 * Source: http://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
 * Description: Prime sieve for generating all primes up to a certain limit. isprime$[i]$ is true iff i$ is a prime.
 * Status: Tested
 * Time: lim=100'000'000 $\approx$ 0.8 s. Runs 30\% faster if only odd indices are stored.
 */
#pragma once

const int MAX_PR = 5'000'000;

int minPrime[N];
void eratosthenesSieve(int lim) {
    for (int i = 4; i < lim; i += 2) minPrime[i] = 2;
    for (int i = 3; i*i < lim; i += 2) if (!minPrime[i])
        for (int j = i*i; j < lim; j += i*2) minPrime[j] = i;
    for (int i = 2 ; i < lim ; i++) {
        if (!minPrime[i]) {
            minPrime[i] = i;
        }
    }
}

int nen(int x) {
    int res = 1; 
    if (x == 1) return x; 
    while (x > 1) {
        int cnt = 0;
        int k = minPrime[x]; 
        while (x % k == 0) {
            x /= k; 
            cnt++;
        }
        if (cnt % 2) {
            res *= k;
        }
    }
    return res;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<int> p(n + 3);
    for (int i = 1 ; i <= n ; i++) {
        p[nen(i)]++;
    }
    int ans = 1;
    for (int i = 1 ; i <= n ; i++) {
        if (p[i]) {
            (ans *= (p[i] + 1))%=m;
        }
    }
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test = 1; 
    eratosthenesSieve(1E6 + 7);
    //cin >> test; 
    while (test--) {
       solve();
    }
}
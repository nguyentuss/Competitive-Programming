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
const int inf = 1e9;

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

const int MAX_PR = 1'0000'001;
bitset<MAX_PR> isprime;
vi eratosthenesSieve(int lim) {
	isprime.set(); isprime[0] = isprime[1] = 0;
	for (int i = 4; i < lim; i += 2) isprime[i] = 0;
	for (int i = 3; i*i < lim; i += 2) if (isprime[i])
		for (int j = i*i; j < lim; j += i*2) isprime[j] = 0;
	vi pr;
	rep(i,2,lim) if (isprime[i]) pr.push_back(i);
	return pr;
}

int g[MAX_PR];

void offline() {
    vi pr = eratosthenesSieve(MAX_PR); 
    int cnt = 1; 
    g[1] = 1;
    vector<bool> vis(MAX_PR);
    vis[1] = 1;
    //cerr << pr[0] << " ";
    for (int x : pr) {
        if (x == 2) continue;
        cnt++;
        for (int i = x ; i < MAX_PR ; i+=x) {
            if (!vis[i] && i%2) {
                vis[i] = true; 
                g[i] = cnt;
            }
        }
    }
    // for (int i = 1 ; i < 100 ; i++) {
    //     cout << g[i] << " ";
    // }
}

void solve() {
    int n; cin >> n;
    int ans = 0;
    for (int i = 0 ; i < n ; i++) {
        int x; cin >> x;
        ans ^= g[x];
    }
    if (ans > 0) cout << "Alice\n";
    else cout << "Bob\n";
}


signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    offline();
    cin >> test;
    while (test--) {
        solve();
    }

}
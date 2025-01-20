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

const int MAX_PR = 5'000'000;
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

void solve() {
    int n; cin >> n;
    vector<int> ans;
    for (int i = 1 ; i <= n ; i += 2) {
        ans.push_back(i);
    }
    set<int> s;
    for (int i = 2 ; i <= n ; i+= 2) {
        s.insert(i); 
    }
    bool ok = false;
    for (int x : s) {
        if (!isprime[ans[sz(ans) - 1] + x]) {
            ans.push_back(x); 
            s.erase(x); 
            ok = true;
            break;
        }
    }
    if (!ok) cout << -1 << '\n';
    else {
        for (int x : ans) cout << x << " "; 
        for (int x : s) cout << x << " "; 
        cout << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    eratosthenesSieve(2E5 + 7);
    int test; 
    test = 1;
    cin >> test;
    while (test--) {
        solve();
    }
 
}

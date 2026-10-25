#include <bits/stdc++.h>
 
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;
 
#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long
const int inf = 1e9 + 7;
const int MAX_N = 1e7 + 7;
const int MOD = 1e9 + 7;

int sieve[MAX_N];
vector<int> v;
int minPrime[MAX_N];

void eratosthene() {
    for (int i = 2 ; i * i < MAX_N ; i++) {
        if (!sieve[i]) {
            for (int j = i*i ; j < MAX_N ; j+=i) {
                if (!sieve[j]) sieve[j] = i;
            }
        }
    }
    for (int i = 2 ; i < MAX_N ; i++) {
        if (sieve[i] == 0) {
            sieve[i] = i;
        }
    }
    return;
}

int f[MAX_N];
int a[MAX_N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    eratosthene();
    int n , q; cin >> n >> q;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        f[i] = f[i - 1] + 1 + sieve[a[i]];
    }
    for (int i = 1 ; i <= q ; i++) {
        int l , r; cin >> l >> r;
        cout << f[r] - f[l - 1] << '\n';
    }
    return 0;
}
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
const int MAX_N = 1e6 + 7;
const int MOD = 1e9 + 7;

int sieve[MAX_N];
vector<int> v;
int minPrime[MAX_N];
int cnt[MAX_N];
int ans = 0;

void eratosthene() {
    for (int i = 2 ; i * i < MAX_N ; i++) {
        if (minPrime[i] == 0) {
            for (int j = i * i ; j < MAX_N ; j+=i) {
                if (minPrime[j] == 0)
                    minPrime[j] = i;
            }
        }
    }
    for (int i = 2 ; i < MAX_N ; i++) {
        if (minPrime[i] == 0) {
            minPrime[i] = i;
        }
    }
    return;
}

void calc(int n) {
    vector<int> v;
    while (n != 1) {
        v.push_back(minPrime[n]);
        n/= minPrime[n];
    }
    v.push_back(0);
    int mul = 1;
    for (int i = 0 ; i < (v.size() - 1) ; i++) {
        if (v[i] != v[i + 1]) {
            mul*=v[i];
        }
    }
    ans += cnt[mul]; 
    cnt[mul]++;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    eratosthene();
    int l , r; cin >> l >> r;
    for (int i = l ; i <= r ; i++) {
        calc(i);
    }
    cout << ans;
    return 0;
}
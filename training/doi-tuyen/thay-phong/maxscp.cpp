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
    vector<int> res;
    while (n != 1) {
        cnt[minPrime[n]]++;
        n/= minPrime[n];
    }
}

int POW(int a , int n) {
    if (n == 0) return 1%MOD;
    int child = POW(a , n / 2)%MOD;
    if (n % 2 == 1) {
        return (child%MOD*child%MOD*a)%MOD;
    }
    else return (child%MOD*child)%MOD;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    eratosthene();
    int n; cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        calc(i);
    }
    int ans = 1;
    for (int i = 2 ; i <= n ; i++) {
        int x = cnt[i] - (cnt[i]%2);
        ans = (ans%MOD*POW(i , x)%MOD)%MOD;
    }
    cout << ans;
    return 0;
}
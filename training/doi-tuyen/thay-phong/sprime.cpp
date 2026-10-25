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
const int MAX_N = 3e6 + 7;
const int MOD = 1e9 + 7;

int sieve[MAX_N];
vector<int> v;

void eratosthene() {
    sieve[1] = true;
    for (int i = 2 ; i < MAX_N ; i++) {
        if (!sieve[i]) {
            for (int j = 2*i ; j < MAX_N ; j+=i) {
                sieve[j] = true;
            }
        }
    }
    for (int i = 2 ; i < MAX_N ; i++) {
        if (!sieve[i]) v.push_back(i);
    }
    return;
}

int f[MAX_N];
int ans[MAX_N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    eratosthene();
    for (auto x : v) {
        int e = x;
        int num = 0;
        while (e) {
            num += (e % 10);
            e /= 10;
        }
        ans[x] = (num % 5 == 0)?1:0;
    }
    for (int i = 1 ; i < MAX_N ; i++) {
        f[i] = f[i - 1] + ans[i];
    }
    int n; cin >> n;
    while (n--) {
        int l , r; cin >> l >> r;
        cout << f[r] - f[l - 1] << '\n';
    }
    return 0;
}
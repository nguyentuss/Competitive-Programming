#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9+7;

long long inv[100005];
long long fac[100005];
const int long long MAXN = 1e5;

typedef long long ll;
ll dec(ll x, ll y, int MOD) {return (x-y+MOD)%MOD;}
ll add(ll x, ll y, int MOD) {return (x + y) % MOD;}
ll mul(ll x, ll y, int MOD) {return ((x%MOD) * (y%MOD)) % MOD;}
ll bpow(ll x, ll y, int MOD) {ll res = 1; while (y) {if (y & 1) res = mul(res, x, MOD); x = mul(x, x, MOD); y >>= 1;} return res;}
ll ModInverse(ll x, int MOD) {return bpow(x, MOD - 2, MOD);}
ll binpower(ll base, ll e, ll mod) {ll result = 1;base %= mod;while (e){if (e & 1)result = (ll)result * base % mod;base = (ll)base * base % mod;e >>= 1;    }return result;}

long long cal(int n, int k) {
    return ((fac[n] * bpow(fac[k] , mod - 2 , mod)%mod)%mod* bpow(fac[n - k] , mod - 2 , mod)%mod)%mod;
}

int main() {
    fac[0] = 1;
	for (int i = 1; i <= MAXN; i++) { fac[i] = (fac[i - 1] * i) % mod; }
    inv[MAXN] = ModInverse(fac[MAXN], mod);
	for (int i = MAXN; i >= 1; i--) { inv[i - 1] = inv[i] * i % mod; }
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        int n,k;
        cin >> n >> k;
        long long res = binpower(2,n,mod);
        for (int i = 0; i < k; i++)
            res = (res-cal(n,i)+mod*mod)%mod;
        //cout << cal(9,6) << "\n";
        cout << "Case " << "#" << tt << ": " << res << "\n";
    }
}
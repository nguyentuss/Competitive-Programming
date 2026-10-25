#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define taskname ""
#define pb push_back
#define pp pop_back
#define w(t) while (t--)
#define all(a) (a).begin(), (a).end()
#define forn(i, a, b) for (int i = a; i < b; i++)
#define pii pair<int, int>
#define int long long
#define ordered_set                              \
    tree<int, null_type, less<int>, rb_tree_tag, \
         tree_order_statistick_node_update>
vector<int> g[1000005];
void edge() {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
}
inline void file_inp(const string FILE = "Test") {
    freopen((FILE + ".I100005P").c_str(), "r", stdin);
}
inline void file_out(const string FILE = "Test") {
    freopen((FILE + ".OUT").c_str(), "w", stdout);
}
inline void file(const string FILE = "Test") {
    file_inp(FILE);
    file_out(FILE);
}

string str(ll num) {
    ll a = num;
    stringstream ss;
    ss << a;
    string str = ss.str();
    return str;
}

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

struct ms {
    int val, pos;
};
bool cmp(ms a, ms b) {
    return (a.val < b.val || (a.val == b.val && a.pos < b.pos));
}

ll binpower(ll base, ll e, ll mod) {
    ll result = 1;
    base %= mod;
    while (e) {
        if (e & 1) result = (ll)result * base % mod;
        base = (ll)base * base % mod;
        e >>= 1;
    }
    return result;
}
bool check_composite(long long n, long long a, long long d, int s) {
    long long x = binpower(a, d, n);
    if (x == 1 || x == n - 1) return false;
    for (int r = 1; r < s; r++) {
        x = (long long)x * x % n;
        if (x == n - 1) return false;
    }
    return true;
};
bool checkprime(long long n) {
    if (n < 2) return false;
    int r = 0;
    long long d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }
    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a) return true;
        if (check_composite(n, a, d, r)) return false;
    }
    return true;
}
bool checksqr(ll k) { return (trunc(sqrt(k)) * trunc(sqrt(k)) == k); }

ll dec(ll x, ll y, int MOD) { return (x - y + MOD) % MOD; }
ll add(ll x, ll y, int MOD) { return (x + y) % MOD; }
ll mul(ll x, ll y, int MOD) { return ((x % MOD) * (y % MOD)) % MOD; }
ll bpow(ll x, ll y, int MOD) {
    ll res = 1;
    while (y) {
        if (y & 1) res = mul(res, x, MOD);
        x = mul(x, x, MOD);
        y >>= 1;
    }
    return res;
}
ll ModInverse(ll x, int MOD) { return bpow(x, MOD - 2, MOD); }
ll Div(ll x, ll y, int MOD) { return mul(x, ModInverse(y, MOD), MOD); }
ll GetBit(ll val, ll num) { return ((val >> num) & 1LL); }

ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
ll sum(ll n) { return n * (n + 1) / 2; }

int a[1000005];
long long res = 0;
int mod = 998244353;
const int maxn = 1000000;

int f[520][520];
int n, m, d[100005];
vector<int> e[100005], se[100005];
int mp[100005], cnt[100005], ns[100005];

/*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------*/

void Gauss() {
    for (int i = 0; i < 512; i++) {
        int cs = -1;
        for (int j = i; j < 512; j++)
            if (f[j][i]) cs = j;
        swap(f[i], f[cs]);
        int Iv = ModInverse(f[i][i], mod);
        for (int j = 0; j < 512; j++)
            if (j != i) {
                int t = mod - (ll)f[j][i] * Iv % mod;
                for (int k = i; k <= 512; k++)
                    (f[j][k] += (ll)t * f[i][k] % mod) %= mod;
            }
    }
    for (int i = 0; i < 512; i++)
        f[i][512] = (ll)f[i][512] * ModInverse(f[i][i], mod) % mod, f[i][i] = 1;
}

void topo() {
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (!d[i]) q.push(i);
    while (!q.empty()) {
        int u = q.front();
        for (int v : e[u]) mp[ns[v]]++;
        while (mp[ns[u]]) ns[u]++;
        for (int v : e[u]) mp[ns[v]]--;
        q.pop();
        for (int v : se[u]) {
            d[v]--;
            if (!d[v]) q.push(v);
        }
    }
    for (int i = 1; i <= n; i++) mp[ns[i]]++;
}

void sol() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v), se[v].push_back(u), d[u]++;
    }
    topo();
    for (int i = 0; i < 512; i++)
        for (int j = 0; j < 512; j++) (f[i][j] += mod - mp[i ^ j]) %= mod;
    for (int i = 0; i < 512; i++) (f[i][i] += n + 1) %= mod;
    f[0][512] = 1;
    Gauss();
    cout << (mod + 1 - f[0][512]) % mod << "\n";
}

signed main() {
    fast;
    // file("");
    int t = 1;
    // cin >> t;
    w(t) {
        sol();
        cout << '\n';
    }
}

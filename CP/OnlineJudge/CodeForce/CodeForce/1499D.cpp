//source:: 
#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define repn(i ,a, b) for(int i = a; i <= (b); ++i)
#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define vi vector<int>
#define fi first
#define se second
#define int long long
#define sz(a) (int) a.size()
typedef unsigned __int128 ull;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int inf = 1e18 + 7;
const int N = 2e7 + 7;
const int MOD = 1e9 + 7;

vector<int> sieve(N);
vector<int> val(N);

void eratosthenes() {
    sieve[1] = 1;
    for (int i = 2 ; i < N ; i++) { 
        if (!sieve[i]) {
            for (int j = i ; j < N ; j += i) {
                if (!sieve[j]) {
                    sieve[j] = i;
                }
            }
        }
    }
    for (int i = 2 ; i < N ; i++) {
        val[i] = val[i / sieve[i]] + (sieve[i] != sieve[i / sieve[i]]);
    }
}
// c*lcm(a , b) - d*gcd(a , b) = x
// a = Ag , b = Bg
// g = gcd(a , b)
// gcd(A , B) = 1
// c*ABg - d*g = x
// AB = (x/g + d)/c (phai chia het vi gcd(A , B) = 1)
// AB = p1^k1 *  p2^k2 * ..
// dap an la 2^k (k la so prime divisor)


void solve() {
    int c , d , x; cin >> c >> d >> x;
    int ans = 0;
    for (int i = 1 ; i * i <= x ; i++) {
        if (x % i != 0) continue;
        int v1 = x / i + d;
        if (v1 % c == 0) ans += 1 << val[v1 / c];
        if (i * i == x) continue;
        int v2 = i + d;
        if (v2 % c == 0) ans += 1 << val[v2 / c];
    }
    cout << ans << '\n';
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test = 1; 
    eratosthenes();
    cerr << "YES";
    cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}
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
const int N = 2e5 + 7;
const int MOD = 1e18 + 7;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    int num1 = 0 , num2 = 0;
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i];
        int x = a[i];
        if (x == 1) {
            num1 += 1; 
        }
        else if (x == 2) {
            num2 += 1; 
        }
        else {
            num2 ++; 
            num1 += x - 2;
        }
    }
    cout << num1/2 + num2/2 << '\n';
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test = 1; 
    cin >> test; 
    while (test--) {
       solve();
    }
}
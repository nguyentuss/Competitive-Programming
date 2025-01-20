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

vector<int> divisor(int n) {
    vector<int> ans;
    for (int i = 1 ; i * i <= n ; i++) {
        if (n % i == 0) {
            if (n/i == i) {
                ans.push_back(i);
            }
            else {
                ans.push_back(i);
                ans.push_back(n/i);
            }
        }
    }
    sort(all(ans)); 
    return ans;
}

void solve() {
    int a , b, c, d; cin >> a >> b >> c >> d;
    int lcm = (a*b)/__gcd(a , b);
    vector<int> c1 = divisor(c);
    vector<int> tmp;
    for (int x : c1) {
        if (x % a == 0 && x % lcm != 0) {
            tmp.push_back(x);
        }
    }
    vector<int> d1 = divisor(d);
    map<int , bool> mp; 
    for (int x : d1) {
        mp[x] = true;
    }
    vector<int> res;
    for (int x : tmp) {
        if (mp[x] == false) {
            res.push_back(x);
        }  
    }   
    if (!sz(res)) {
        cout << -1;
        return;
    }
    cout << res[0];
    //for (int x : res) cout << x << " ";
    
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    //cin >> test;
    while (test--) {
        solve();
    }

}
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

bool compare(int l, int w, int r1, int r2)
{
    int lowest = l < w ? l : w;
    
    if (r1 * 2 > lowest || r2 * 2 > lowest)
        return false;
    
    int x = l - r1 - r2, y = w - r1 - r2, r = r1 + r2;
    
    if (x * x + y * y >= r * r)
    {
        return true;
    }
    
    return false;
}


void solve() {
    int l , w , r1 , r2; 
    while (cin >> l >> w >> r1 >> r2 && l && w && r1 && r2) {
        if (compare(l , w , r1 , r2)) cout << "S\n"; 
        else cout << "N\n";
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test = 1; 
    //cin >> test; 
    while (test--) {
       solve();
    }
}
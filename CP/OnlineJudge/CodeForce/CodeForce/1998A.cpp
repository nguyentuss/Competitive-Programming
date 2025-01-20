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

void solve() {
    int xc , yc , k; cin >> xc >> yc >> k;
    int vlx = xc * k , vly = yc * k;
    if (k == 1) {
        cout << xc << " " << yc << '\n';
        return;
    }
    int remain = k % 2; 
    if (!remain) {
        if (xc == 0 && yc == 0) {
            cout << -10000 << ' ' << -10000 << '\n';
            cout << 10000 << ' ' << 10000 << '\n';
        }
        else {
            cout << "0 0\n"; 
            cout << xc*k << " " << yc*k << '\n';
        }
    }
    else {
        cout << xc*k << " " << yc*k << '\n';
    }
    int x = 1 , y = 1;
    for (int i = 0 ; i < k - (!remain ? 2 : 1); i+=2){
        while (x == xc*k && y == yc*k && -x==xc*k && -y==yc*k) {
            x++; y++;
        }
        cout << x << " " << y << '\n';
        cout << -x << " " << -y << '\n';
        x++; y++;
    }
    //cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    cin >> test;
    while (test--) {
        solve();
    }

}
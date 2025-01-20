//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define le(x) (x << 1ll)
#define ri(x) ((x << 1ll) + 1)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double , double> pdd;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int inf = 1e9;

double sqr(double x) {
    return x * x;
}

void solve() {
    double R , x1 , y1 , x2 , y2; cin >> R >> x1 >> y1 >> x2 >> y2; 
    if (sqr(x2 - x1) + sqr(y2 - y1) <= sqr(R)) {
        if (x2 == x1 && y1 == y2) {
            cout << fixed << setprecision(10) << x1 + R/2.0 << " " << y2 << " " << R/2.0 << '\n';
            return;
        }
        double last = R - sqrt(sqr(x2 - x1) + sqr(y2 - y1));
        double diameter = 2.0*R - last;
        double k = diameter/sqrt(sqr(x2 - x1) + sqr(y2 - y1));
        pdd AB = pdd(k*(x1 - x2) , k*(y1 - y2));
        pdd B = pdd(x2 + AB.first , y2 + AB.second);
        pdd med = pdd((x2 + B.first)/2.0 , (y2 + B.second)/2.0);
        cout << fixed << setprecision(10) << med.first << " " << med.second << " " << diameter/2.0 << '\n';
    }
    else {
        cout << fixed << setprecision(10) << x1 << " " << y1 << " " << R << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    // cin >> test;
    while (test--) {
        solve();
    }

}
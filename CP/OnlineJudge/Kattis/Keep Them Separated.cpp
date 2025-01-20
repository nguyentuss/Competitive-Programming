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
const int mod = 1e9 + 7;

/**
 * Author: Simon Lindholm
 * Date: 2017-05-11
 * License: CC0
 * Source: folklore
 * Description: Computes sums a[i,j] for all i<I, j<J, and increases single elements a[i,j].
 *  Requires that the elements to be updated are known in advance (call fakeUpdate(), then init()).
 * Time: $O(\log^2 N)$. (Use persistent segment trees for $O(\log N)$.)
 * Status: stress-tested
 */
/**
 * Author: Lukas Polacek
 * Date: 2009-10-30
 * License: CC0
 * Source: folklore/TopCoder
 * Description: Computes partial sums a[0] + a[1] + ... + a[pos - 1], and updates single elements a[i],
 * taking the difference between the old and new value.
 * Time: Both operations are $O(\log N)$.
 * Status: Stress-tested
 */

void add(int &a , int b) {
    (a += b)%=mod;
}

struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) add(s[pos] , dif);
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) add(res , s[pos - 1]); 
		return res;
	}
};


struct FT2 {
	vector<vi> ys; vector<FT> ft;
	FT2(int limx) : ys(limx) {}
	void fakeUpdate(int x, int y) {
		for (; x < sz(ys); x |= x + 1) ys[x].push_back(y);
	}
	void init() {
		for (vi& v : ys) sort(all(v)), ft.emplace_back(sz(v));
	}
	int ind(int x, int y) {
		return (int)(lower_bound(all(ys[x]), y) - ys[x].begin()); }
	void update(int x, int y, ll dif) {
		for (; x < sz(ys); x |= x + 1)
			ft[x].update(ind(x, y), dif);
	}
	ll query(int x, int y) {
		ll sum = 0;
		for (; x; x &= x - 1)
            add(sum , ft[x-1].query(ind(x-1,y)));
		return sum;
	}
};

const int base = 200003; 

void solve() {
    int q; cin >> q; 
    vector<vi> g(q);
    FT2 bit(5007);
    map<pair<int , int> , bool> mp;
    for (int i = 0 ; i < q ; i++) {
        int type; cin >> type; 
        if (type == 1 || type == 3) {
            int x1 , y1 , x2 , y2; cin >> x1 >> y1 >> x2 >> y2;
            g[i].emplace_back(type);
            g[i].emplace_back(x1);
            g[i].emplace_back(y1);
            g[i].emplace_back(x2);
            g[i].emplace_back(y2);
            if (mp.find({x1 , y1}) == mp.end()) bit.fakeUpdate(x1 , y1) , mp[{x1 , y1}] = true;
            if (mp.find({x1 , y2}) == mp.end()) bit.fakeUpdate(x1 , y2) , mp[{x1 , y2}] = true;
            if (mp.find({x2 , y2}) == mp.end()) bit.fakeUpdate(x2 , y2) , mp[{x2 , y2}] = true;
            if (mp.find({x2 , y1}) == mp.end()) bit.fakeUpdate(x2 , y1) , mp[{x2 , y1}] = true;
        } 
        else {
            int j; cin >> j;
            g[i].emplace_back(type); 
            g[i].emplace_back(j);
        }
        
    }
    bit.init();
    vector<int> pw(q + 1);
    pw[0] = 1ll;
    for (int i = 1 ; i <= q ; i++) {
        pw[i] = (1ll * pw[i - 1] * base)%mod;
    }
    for (int i = 0 ; i < q ; i++) {
        int j = i + 1;
        int type = g[i][0]; 
        if (type == 1) {
            int x1 = g[i][1];
            int y1 = g[i][2]; 
            int x2 = g[i][3];
            int y2 = g[i][4]; 
            bit.update(x1 , y1 , pw[j]);
            bit.update(x2 , y2 , pw[j]);
            bit.update(x1 , y2 , -pw[j] + mod); 
            bit.update(x2 , y1 , -pw[j] + mod);
        }
        if (type == 2) {
            int k = g[i][1];
            k--;
            int x1 = g[k][1];
            int y1 = g[k][2]; 
            int x2 = g[k][3];
            int y2 = g[k][4]; 
            bit.update(x1 , y1 , -pw[k + 1] + mod);
            bit.update(x2 , y2 , -pw[k + 1] + mod);
            bit.update(x1 , y2 , pw[k + 1]); 
            bit.update(x2 , y1 , pw[k + 1]);
        }
        if (type == 3) {
            int x1 = g[i][1];
            int y1 = g[i][2]; 
            int x2 = g[i][3];
            int y2 = g[i][4];
            //cerr << bit.query(x1 , y1) << " " <<  bit.query(x2 , y2) << '\n';
            if (bit.query(x1 , y1) == bit.query(x2 , y2)) {
                cout << "Y";
            }
            else cout << "N";
        }
    }
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
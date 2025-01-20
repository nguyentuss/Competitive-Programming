//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

/**
 * Author: Simon Lindholm
 * Date: 2015-03-15
 * License: CC0
 * Source: own work
 * Description: Various self-explanatory methods for string hashing.
 * Use on Codeforces, which lacks 64-bit support and where solutions can be hacked.
 * Status: stress-tested
 */
struct H {
	typedef uint64_t ull;
	ull x; H(ull x=0) : x(x) {}
#define OP(O,A,B) H operator O(H o) { ull r = x; asm \
	(A "addq %%rdx, %0\n adcq $0,%0" : "+a"(r) : B); return r; }
	OP(+,,"d"(o.x)) OP(*,"mul %1\n", "r"(o.x) : "rdx")
	H operator-(H o) { return *this + ~o.x; }
	ull get() const { return x + !~x; }
	bool operator==(H o) const { return get() == o.get(); }
	bool operator<(H o) const { return get() < o.get(); }
};
static const H C = (ll)311 + 3; // (order ~ 3e9; random also ok)

struct HashInterval {
	vector<H> ha, pw;
	HashInterval(string& str) : ha(sz(str)+1), pw(ha) {
		pw[0] = 1;
		rep(i,0,sz(str))
			ha[i+1] = ha[i] * C + str[i],
			pw[i+1] = pw[i] * C;
	}
	H hashInterval(int a, int b) { // hash [a, b)
		return ha[b] - ha[a] * pw[b - a];
	}
};

H hashString(string& s){H h{}; for(char c:s) h=h*C+c;return h;}

bool check(int X , HashInterval &f , string &s , int k) {
    int hs = f.hashInterval(0 , X).x;
    int cnt = 1;
    for (int i = X ; i < (int) s.size() ; i++) {
        if ((i + X) > s.size()) break;
        if (f.hashInterval(i , i + X).x == hs) {
            cnt++; 
            i = i + X - 1;
            //cerr << i << " ";
        }
    }
    return (cnt >= k);
}

const int N = 2e5 + 7;

int pw[N];

void solve() {
    int n , k; cin >> n >> k;
    string s; cin >> s;
    string A = ""; 
    string B = "";
    bool status = 0;
    for (int i = 0 ; i < sz(s) ; i += k) {
        for (int j = 0 ; j < k ; j++) {
            if (!status) {
                A += "0";
            }
            else A += "1";
        }
        status ^= 1; 
    }
    status = 0;
    for (int i = 0 ; i < n ; i += k) {
        for (int j = 0 ; j < k ; j++) {
            if (!status) {
                B += "1";
            }
            else B += "0";
        }
        status ^= 1;
    }
    //cerr << A << " " << B << '\n';
    string tm = s;
    reverse(tm.begin() , tm.end());
    //reverse(s.begin(), s.end());
    HashInterval f(s); 
    HashInterval a(A); 
    HashInterval b(B);
    HashInterval tm_h(tm); 
    int res = 0;
    bool stat = false;
    for (int i = 0 ; i < n ; i++) {
        H c = (tm_h.hashInterval(n - i - 1 , n) + f.pw[i+1]*f.hashInterval(i + 1 , n));
        if (c == a.hashInterval(0 , n) || c == b.hashInterval(0 , n)) {
            cout << i + 1 << '\n';
            stat = true;
            break;
        }
    }
    if (!stat) cout << -1 << '\n';
}


signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int test; cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}
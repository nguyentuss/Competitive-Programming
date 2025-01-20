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
#pragma once

typedef uint64_t ull;
static int C; // initialized below

// Arithmetic mod two primes and 2^32 simultaneously.
// "typedef uint64_t H;" instead if Thue-Morse does not apply.
template<int M, class B>
struct A {
	int x; B b; A(int x=0) : x(x), b(x) {}
	A(int x, B b) : x(x), b(b) {}
	A operator+(A o){int y = x+o.x; return{y - (y>=M)*M, b+o.b};}
	A operator-(A o){int y = x-o.x; return{y + (y< 0)*M, b-o.b};}
	A operator*(A o) { return {(int)(1LL*x*o.x % M), b*o.b}; }
	explicit operator ull() { return x ^ (ull) b << 21; }
};
typedef A<1000000007, A<1000000009, unsigned>> H;

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

vector<H> getHashes(string& str, int length) {
	if (sz(str) < length) return {};
	H h = 0, pw = 1;
	rep(i,0,length)
		h = h * C + str[i], pw = pw * C;
	vector<H> ret = {h};
	rep(i,length,sz(str)) {
		ret.push_back(h = h * C + str[i] - pw * str[i-length]);
	}
	return ret;
}

H hashString(string& s){H h{}; for(char c:s) h=h*C+c;return h;}

#include <sys/time.h>

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

void solve() {
    int n , l , r; cin >> n >> l >> r;
    //int k = l;
    string s; cin >> s;
    HashInterval f(s); 
    //cout << check(2 , f , s , k);
    for (int k = 1 ; k <= 100 ; k ++) {
        l = 1 , r = n;
        int ans = 0;
        while (l <= r) {
            int mid = (l + r)/2; 
            if (check(mid , f , s , k)) {
                l = mid + 1;
                ans = mid;
            }
            else r = mid - 1;
        }
    //cout << f.hashInterval(0 , 2).x << " " << f.hashInterval(7 , 9).x;

    cout << ans << '\n';
    }
}


signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	timeval tp;
	gettimeofday(&tp, 0);
	C = (int)tp.tv_usec; // (less than modulo)
	assert((ull)(H(1)*2+1-3) == 0);
	int test; cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}
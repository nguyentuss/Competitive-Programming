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

const int inf = 1e9;
const int N = 2e5 + 7;

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


pair<int , bool> check(int X , HashInterval &f , string &s , int k  , int n) {
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
	return pair<int , bool>(cnt , cnt >= k);
}

void solve() {
    int n , left , right; cin >> n >> left >> right;
    //cerr << left << " " << right << '\n';
    string s; cin >> s;
    //cerr << "YES";
    HashInterval f(s); 
	int prev = n;
	int prev_sl = 0;
    for (int k = left ; k <= right ; k ++) {
		if (prev_sl >= k) {
			cout << prev << " ";
		}
        else {
			int l =1;
			int r = prev; 
			int ans = 0;
			int sl = 0;
			while (l <= r) {
				int mid = (l + r)/2; 
				auto tm = check(mid , f , s , k , n);
				if (tm.second) {
					l = mid + 1;
					ans = mid;
					sl = tm.first;
				}
				else r = mid - 1;
			}
			prev = ans;
			prev_sl = sl;
			cout << ans << " ";
		}
    }
    cout << '\n';
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
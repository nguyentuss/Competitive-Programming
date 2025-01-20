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

/**
 * Author: Tomatoes
 * Date: 2023-07-29
 * License: CC0
 * Source: Tomatoes
 * Description: Matrix operations (not necessarily square mats).
 * Matrix pow can only be on square matrices.
 * Status: tested on yosupo judge
 */
#pragma once
int mod;

int mul(int a , int b) {
    if (b == 0) return 0;
    int child = mul(a , b/2)%mod;
    if (b & 1) return (2ll*(child)%mod + a%mod)%mod;
    else return (2ll*child)%mod;
}

template<class T> struct Matrix {
	int n, m; vector<vector<T>> d;
	Matrix(int n, int m) : n(n), m(m), d(n, vector<T>(m)) {}

	Matrix operator*(const Matrix& o) const {
		assert(m == o.n); Matrix a(n, o.m);
		rep(i,0,n) rep(k,0,m) rep(j,0,o.m) // order matters
			(a.d[i][j] += mul(d[i][k] , o.d[k][j])%mod)%=mod;
		return a;
	}
	vector<T> operator*(const vector<T>& vec) const {
		assert(m == sz(vec)); vector<T> a(n);
		rep(i,0,n) rep(j,0,m) (a[i] += mul(d[i][j] , vec[j])%mod)%=mod;
		return a;
	}
	Matrix operator^(ll e) const {
		assert(e >= 0 && n == m); Matrix a(n, n), b(*this);
		rep(i,0,n) a.d[i][i] = 1;
		for (; e; e >>= 1, b = b * b) if (e & 1) a = a * b;
		return a;
	}
};

int gcd(int a , int b) {
    if (b == 0ll) return a; 
    else return gcd(b , a % b);
}

// gcd(f_a , f_b) = f_gcd(a , b)

void solve() {
    int a , b; cin >> a >> b >> mod;
    int g = gcd(a , b);
    if (g <= 2) {
        cout << 1;
        return;
    }
    Matrix<int> M(2 , 2);
    M.d[0][0] = M.d[0][1] = M.d[1][0] = 1; 
    Matrix<int> B(2 , 1); 
    B.d[0][0] = B.d[1][0] = 1;
    M = M ^ (g - 1);
    //cerr << "YES";
    M = M * B;
    cout << M.d[1][0];

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
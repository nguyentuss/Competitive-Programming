#include <bits/stdc++.h>

using namespace std;

set<int> s3;
set<int , greater<int>> s4;
set<int , greater<int>> s1;
set<int> s2;

map<int , int> m;
int n , q;

void query1(int u , int v) {
	s1.insert(u);
	s2.insert(v);
	m[u] = v;
	m[v] = u;
}

void query2(int u , int v) {
	if (1 <= u && u <= n) {
		if (u > v) s3.insert(u);
		else s3.insert(v);
	}
	if ((n + 1) <= u && u <= 2*n) {
		if (u < v) s4.insert(u);
		else s4.insert(v);
	}
}

void calc1(int u , int v , int crx) {
	auto it = s3.lower_bound(u);

	if (it == s3.end() || *it > crx) 
		cout << "YES" << '\n';
	else cout << "NO" << '\n';
}

void calc2(int u , int v , int crx) {
	auto it = s4.lower_bound(u);
	if (it == s4.end() || *it < crx) cout << "YES" << '\n';
	else cout << "NO" << '\n';
}

void query3(int u , int v) {
	if (1 <= u && u <= n && 1 <= v && v <= n) {
		if (u <= v) {
			auto it = s3.lower_bound(u);
			if (it == s3.end() || *it > v) cout << "YES" << '\n';
			else cout << "NO" << '\n';
		}
		else cout << "NO" << '\n';
	}
	else if ((n + 1) <= u && u <= 2*n && (n + 1) <= v && v <= 2*n) {
		if (u <= v) cout << "NO" << '\n';
		else {
			auto it = s4.lower_bound(v);
			if (it == s4.end() || *it < v) cout << "YES" << '\n';
			else cout << "NO" << '\n';
		}
	}
	else if (1 <= u && u <= n && (n + 1) <= v && v <= 2*n) {
		if ((u + n) <= v) {
			int x = *s2.lower_bound(v);
			int crx = m[x];
			if (crx == u) cout << "YES" << '\n';
			else if (crx > u) calc1(u , v , crx);
			else cout << "NO" << '\n';;
		}
		else {
			int crx = m[v];
			if (crx == u) cout << "YES" << '\n';
			else if (crx > u) calc1(u , v , crx);
			else cout << "NO" << '\n';	
		}
	}
	else if (1 <= v && v <= n && (n + 1) <= u && u <= 2*n) {
		if ((v + n) <= u) {
			int x = *s1.lower_bound(v);
			int crx = m[x];
			if (crx == u) cout << "YES" << '\n';
			else if (crx < u) calc2(u , v , crx);
		}
		else {
			int crx = m[v];
			if (crx == u) cout << "YES" << '\n';
			else if (crx > u) calc2(u , v , crx);
			else cout << "NO" << '\n';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	freopen("test.inp","r",stdin);
	cin >> n >> q;
	for (int i = 1 ; i <= q ; i++) {
		char a;
		int u , v; cin >> a >> u >> v;
		if (a == 'A') query1(u , v);
		if (a == 'B') query2(u , v);
		if (a == 'Q') query3(u , v);
	}


	return 0;
}
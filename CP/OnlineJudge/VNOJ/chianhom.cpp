#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (4e4 + 7)

set<int> s;
int f[MAX_N];
int v[MAX_N] , d[MAX_N];
int last[MAX_N];
int minsize;

int calc(int x) {
	int cnt = 0;
	for (cnt = 0 ; cnt <= minsize && f[cnt] - 1 != x; cnt++);
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);cin.tie(NULL);
	cout.tie(NULL);
	int n , m; cin >> n >> m;
	for (int i = 1 ; i <= n ;i++) {
		cin >> v[i];
		last[i] = -1;
	}
	v[0] = -1;
	minsize = sqrt(n);
	f[0] = 1;
	for (int i = 1 ; i <= n ; i++) {
		int k = last[v[i]];
		int cnt = calc(k);
		cout << cnt << '\n';
		for (int j = cnt - 1 ; j >= 0 ; j--) f[j + 1] = f[j];
		f[0] = i + 1;
		d[i] = i;
		for (int j = 1 ; j <= minsize ; j++) {
			d[i] = min(d[i] , d[f[j] - 1] + j*j);
		}
		last[v[i]] = i;
	}
	cout << d[n];
	return 0;
}
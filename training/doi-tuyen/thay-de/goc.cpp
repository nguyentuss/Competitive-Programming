#include <bits/stdc++.h>

using namespace std;

int a[17] , b[17];
int cnt[362];
int x;
int n , k;

void DFS(int x) {
	for (int i = 0 ; i < n ;i++) {
		int num = x + a[i];
		if (num > 360) num %= 360;
		if (cnt[num]) continue;
		cnt[num] = true;
		DFS(num);
	}
	for (int i = 0 ; i < n ; i++) {
		int num = x - a[i];
		if (num < 0) num = -num;
		if (cnt[num]) continue;
		cnt[num] = 1;
		DFS(num);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("goc.inp","r",stdin);
	freopen("goc.out","w",stdout);
	cin >> n >> k;
	for (int i = 0 ; i < n ; i++) {
		cin >> a[i];
		cnt[a[i]] = 1; 
		DFS(a[i]);
	}
	for (int i = 0 ; i <= 360 ; i++) {
		if (cnt[i]) DFS(i);
	}
	for (int i = 0 ; i < k; i++) {
		int x; cin >> x;
		if (cnt[x]) cout << "YES" << '\n';
		else cout << "NO" << '\n'; 
	}
	return 0;
}
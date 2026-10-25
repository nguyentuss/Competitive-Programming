#include <bits/stdc++.h>

using namespace std;

#define MAX_R (int) (362) 

int n , k;
int a[12];
bool d[362];

void DFS(int num) {
	for (int i = 1 ; i <= n ; i++) {
		int x = num + a[i];
		if (x > 360) x -= 360;
		if (d[x]) continue;
		d[x] = d[360 - x] = 1;
		DFS(x);
		DFS(360 - x);
	}
	for (int i = 1; i <= n ;i++) {
		int x = num - a[i];
		if (x < 0) x = -x;
		if (d[x]) continue;
		d[x] = d[360 - x] = 1;
		DFS(x);
		DFS(360 - x);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	for (int i = 1 ; i <= n ; i++) {
		cin >> a[i];
	}
	for (int i = 1 ; i <= n ; i++) {
		d[a[i]] = 1;
		DFS(a[i]);
	}
	for (int i = 0 ; i <= 360 ; i++) {
		if (d[i]) DFS(i);
	}
	for (int i = 1 ; i <= k ; i++) {
		int tmp ; cin >> tmp;
		if (d[tmp]) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}
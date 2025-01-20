#include <bits/stdc++.h>

using namespace std;
//#pragma GCC optimize("Ofast")


int n , d;
int f[30100][2007];
int cnt[30007];

int DFS(int u , int jump) {
	if (f[u][jump] >= 0) return f[u][jump];
	int res = 0;
	for (int i = -1 ; i <= 1 ; i++) {
		int v = u + jump + i;
		if (v > 30001 || v <= u) continue;
		res = max(res , DFS(v , jump + i));
	}
	return (f[u][jump] = max(f[u][jump] , res + cnt[u]));
}

int main() {
	//freopen("test.inp","r",stdin);
	//freopen("test.out","w",stdout);
	memset(f , -1 , sizeof(f));
	cin >> n >> d;
	for (int i = 0 ; i < n; i++) {
		int x; cin >> x;
		cnt[x]++;	
	}
	cout << DFS(d , d);
	return 0;
}
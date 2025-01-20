#include <bits/stdc++.h>

using namespace std;

int V , E;
bitset<2007> s[2007];

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> V >> E;
	int u , v;
	for (int i = 1 ; i <= E ; i++) {
		cin >> u >> v;
		s[u][v] = true;
		s[v][u] = true;
	}
	long long ans = 0;
	bitset<2007> b;
	for (int i = 1 ; i <= V ; i++) {
		for (int j = i + 1 ; j <= V ; j ++) {
			if (i != j && s[i][j] && s[j][i]) {
				b = s[i]&s[j];
				ans += b.count();
			}
		}
	}
	cout << ans/3;
	return 0;
}
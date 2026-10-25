#include <bits/stdc++.h>
#include <string.h>

using namespace std;

#define MAX_N (int) (2e3 + 7)

map<string , int> num;
vector<int> adj[MAX_N];
int f[MAX_N];	

void DFS(int u , int father) {
	for (auto v : adj[u]) {
		if (v == father) continue;
		f[v] = f[u] + 1;
		DFS(v , u);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	num["polycarp"] = 1;
	int n; cin >> n;
	int pos = 1;
	for (int i = 1 ; i <= n ; i++) {
		string a , b , tmp; cin >> a >> tmp >>  b;
		for (int j = 0 ; j < a.size() ; j++) 
			a[j] = tolower(a[j]);
		for (int j = 0 ; j < b.size() ; j++)
			b[j] = tolower(b[j]);
		pos++;
		num[a] = pos;
		adj[num[b]].push_back(pos);
		adj[pos].push_back(num[b]);
	}
	DFS(1 , -1);
	int ans = 0;
	for (int i = 1 ; i <= pos ; i++) ans = max(ans , f[i]);
	cout << ans + 1; 
	return 0;
}
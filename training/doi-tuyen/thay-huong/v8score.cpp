#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int> 
#pragma GCC optimize("Ofast")

int s , k , n;
ii f[1000][1000];
vector <int> adj[2000];
vector <int> num(2000);
vector <bool> visited(2000,false);
bool check = false;
vector <int> ans;

void DFS(int u , int d , int sum) {
	//visited[u] = true;
	if (d == k && sum == s) {
		ans.push_back(num[u]);
		check = true;
		return;
	}
	if (sum > s) return;
	for (auto v : adj[u]) {
		if (num[u] <= num[v] && ((s - sum)/(k - d)) >= num[v] ) {
			DFS(v , d + 1 , sum + num[v]);
			if (check) {
				ans.push_back(num[u]);
				return;
			}
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int counted = 0;
	cin >> s >> k >> n;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= k ; j ++){
			cin >> f[i][j].first;
		}
	}
	counted = 0;
	for (int i = 1 ; i <= k ; i ++) {
		for (int j = 1 ; j <= n ; j++) {
			counted ++;
			f[j][i].second = counted;
			num[counted] = f[j][i].first;
		}
	}
	for (int i = 1 ; i < k ; i++) {
		for (int j = 1 ; j <= n ; j ++) 
			for (int h = 1 ; h <= n ; h ++) {
				adj[f[j][i].second].push_back(f[h][i + 1].second);
			}
	}
	for (int i = 1 ; i <= n ; i++) {
		DFS(i , 1 , num[i]);
		if (check) {
			cout << "YES" << '\n';
			reverse(ans.begin() , ans.end());
			for (auto e : ans) cout << e << " ";
			return 0;
		}
	}
	cout << "NO";

	return 0;
}
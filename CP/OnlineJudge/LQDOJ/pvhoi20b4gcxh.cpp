#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e4 + 7)
#define ii pair<int ,int>
#define u first
#define v second
#define mod (int) (998244353)

int n , m;
int root[MAX_N];
vector<ii> adj;
int len[MAX_N];
int sum[MAX_N];
int cnt[MAX_N];

void init() {
	for (int i = 1 ; i <= 3007 ; i++) {
		root[i] = i;
		len[i] = 1;
		cnt[i] = 0;
		sum[i] = 0;
	}
}
 
int findroot(int x) {
	if (x == root[x]) return x;
	else {
		root[x] = findroot(root[x]);
		return root[x];
	}
}
 
void unionset(int x , int y) {
	int u = findroot(x);
	int v = findroot(y);
	if (u != v) {
		if (len[u] < len[v]) swap(u , v);
		root[v] = u;
		if (len[u] == len[v]) len[u] += len[v];
		len[u] += len[v];
	}
}
bool checking(int u , int v) {
	int rootu = findroot(u);
	int rootv = findroot(v);
	if (rootu == rootv) return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	int t; cin >> t;
	if (t <= 2) {
		init();
		cin >> n >> m;
		for (int i = 0 ; i < m ; i++) {
			int u , v; cin >> u >> v;
			adj.push_back(ii(u , v));
		}
		for (int i = 1 ; i <= n ;i++) {
			init();
			for (auto edge : adj) {
				if (edge.u != i && edge.v != i) {
					unionset(edge.u , edge.v);
				}
			}
			for (int j = 1 ; j <= n ; j++){
				int x = root[findroot(j)];
				if (x != i) cnt[x] ++;
			}
			vector<int> tmp;
			for (int j = 1 ; j <= n ; j++) {
				if (cnt[j]) 
					tmp.push_back(cnt[j]);
			}
			int len = tmp.size();
			sum[i] = 0;
			for (int j = 1 ; j <= len ; j++) 
				(sum[j] = sum[j - 1] + tmp[j - 1])%=mod;
			int ans = 0;
			for (int j = 1 ; j <= len ; j++) {
				(ans += (tmp[j - 1]*sum[j - 1])%mod)%mod;
			}
			cout << ans << " ";
		}
		cout << '\n';
		for (int i = 0 ; i < adj.size() ; i ++) {
			init();
			for (int j = 0 ; j < adj.size() ; j++) {
				if (i != j) 
					unionset(adj[j].u , adj[j].v);
			}
			for (int j = 1 ; j <= n ; j++){
				int x = root[findroot(j)];
				if (x != i) cnt[x] ++;
			}
			vector<int> tmp;
			for (int j = 1 ; j <= n ; j++) {
				if (cnt[j]) 
					tmp.push_back(cnt[j]);
			}
			int len = tmp.size();
			sum[i] = 0;
			for (int j = 1 ; j <= len ; j++) 
				(sum[j] = sum[j - 1] + tmp[j - 1])%=mod;
			int ans = 0;
			for (int j = 1 ; j <= len ; j++) {
				(ans += (tmp[j - 1]*sum[j - 1])%mod)%=mod;
			}
			cout << ans << " ";
		}
	}
	return 0;
}
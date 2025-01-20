#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e3 + 7)

struct edge {
	int u , l , r;
};

struct ele {
	int l , r;
};

int n , m;
vector <edge> adj[MAX_N];
vector <int> key;
vector<ele> seg;
bool vis[MAX_N];

bool BFS(int l , int r) {
	memset(vis , false , sizeof vis);
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		if (u == n) return true;
		for (auto v : adj[u]) {
			int newl = v.l , newr = v.r;
			if (l >= newl && r <= newr && !vis[v.u]) {
				q.push(v.u);
				vis[v.u] = true;
			}  
		}
	}
	return false;
}
bool check(int l , int r) {
	int newl = seg[l].l;
	int newr = seg[l].r;
	for (int i = l + 1 ; i <= r ; i++) {
		if ((newr + 1) == seg[i].l) newr = seg[i].r;
		else return false;
	}
	return BFS(newl , newr);
}

int binarysearch(int l , int r , int x) {
	if (l > r) return -1;
	int mid = (l + r)/2;
	if (check(x , mid)) return max(mid , binarysearch(mid + 1 , r , x));
	return binarysearch(l , mid - 1 , x);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	cin >> n >> m;
	for (int i = 1 ; i <= m ; i++) {
		int u , v, l , r; cin >> u >> v >> l >> r;
		if (u == v) continue;
		adj[u].push_back({v , l , r});
		adj[v].push_back({u , l , r});
		key.push_back(l - 1);
		key.push_back(r);
	}
	key.push_back(0); key.push_back(10000000);
	sort(key.begin() , key.end());
	for (int i = 1 ; i < key.size() ; i++) {
		if ((key[i - 1] + 1) > key[i]) continue;
		cout << key[i - 1] + 1 << " " << key[i] << '\n';
		seg.push_back({key[i - 1] + 1, key[i]});
	}
	int res = 0;
	for (int i = 0 ; i < seg.size() ; i++) {
		int id = binarysearch(0 , seg.size() - 1 , i);
		if (id == -1) continue;
		res = max(res , seg[id].r - seg[i].l + 1);
	}
	if (res == 0) cout << "Nice work, Dima!";
	else cout << res;
	return 0;
}

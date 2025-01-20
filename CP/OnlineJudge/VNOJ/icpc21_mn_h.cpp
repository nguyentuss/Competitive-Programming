#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)
#define ii pair<int ,int>
#define iii pair<int , ii>
#define f first 
#define s second

vector<int> adj[MAX_N];
vector<int> edge[MAX_N];
vector<iii> a;
int H[MAX_N] , F[MAX_N];
int pos[MAX_N];

void up(int u , int father) {
	vector<int> tmp;
	int max1 = 0 , max2 = 0;
	for (auto v : adj[u]) {
		if (v != father) {
			H[v] = H[u] + 1;
			tmp.push_back(F[v] + 1);
		}
	}
	sort(tmp.begin() , tmp.end() , greater<int>());
	if (tmp.size() > 1) {
		max1 = tmp[0] , max2 = tmp[1];
		for (auto v : adj[u]) {
			if (v != father) {
				if (max1 == (F[v] + 1) && max2 != (F[v] + 1)) {
					H[v] = max(H[v] , max2 + 1);
				} 
				else H[v] = max(H[v] , max1 + 1);
			}
		}
	}
	for (auto v : adj[u]) {
		if (v != father) {
			up(v , u);
		}
	}
}

void down(int u , int father) {
	F[u] = 0;
	for (auto v : adj[u]) {
		if (v != father) {
			down(v , u);
			F[u] = max(F[u] , F[v] + 1); 
		}
	}
}

void DFS(int u , int father) {
	edge[u].push_back(H[u]);
	for (auto v : adj[u]) {
		if (v != father) {
			edge[u].push_back(F[v] + 1);
			DFS(v , u);	
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	//freopen("test.out","w",stdout);
	int n , m; cin >> n >> m;
	for (int i = 1 ; i < n ; i++) {
		int u , v ; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	down(1 , -1);
	up(1 , -1);
	DFS(1 , -1);
	//for (int i = 1 ; i <= n ;i ++) {
	//	cout << H[i] << " " << F[i] << '\n';
	//}
	for (int i = 1 ; i <= n ; i++) {
		sort(edge[i].begin() , edge[i].end());
	}
	for (int i = 1 ; i <= m ; i++) {
		int u , x; cin >> u >> x;
		a.push_back(iii(u , ii(x , i)));
	}
	sort(a.begin() , a.end());
	//for (auto x : a) {
	//	cout << x.f << " " << x.s.f << " " << x.s.s << '\n';
	//}
	vector<ii> query;
	for (int i = 0 ; i < m ; i++) {
		int u = a[i].f , len = edge[u].size();
		int x = a[i].s.f;
		while (pos[u] < len && edge[u][pos[u]] <= x) pos[u]++;
		query.push_back(ii(a[i].s.s , len - pos[u]));
	}
	sort(query.begin() , query.end());
	for (auto x : query) {
		cout << x.s << '\n';
	} 
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define oo (int) (1e9 + 7)
#define ii pair<int , int>

int n , m , k , s , t , u , v , q;
vector <ii> adj[10007] , readj[10007];
vector <int> dstart(10007) , dend(10007);
vector <int> D(10007);
void init() {
	for (int i = 1 ; i <= n ; i++) {
		adj[i].clear();
		readj[i].clear();
		dstart[i] = oo;
		dend[i] = oo;
	}
	return;
}

vector <int> disjktra(int start , vector <ii> a[10007]) {
	priority_queue<ii , vector <ii> , greater<ii>> pq;
	for (int i = 1 ; i <= n ; i++) 
		D[i] = oo;
	D[start] = 0;
	pq.push(ii(0 , start));
	while (!pq.empty()) {
		int u = pq.top().second;
		int du = pq.top().first;
		pq.pop();
		ii e;
		for (auto e : a[u]) {
			if (D[e.first] > du + e.second) {
				D[e.first] = du + e.second;
				pq.push(ii(D[e.first] , e.first));
			}
		}
	}
	return D;
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cout.tie(NULL);

	int test; cin >> test;
	while (test--) {
		cin >> n >> m >> k >> s >> t;
		init();
		for (int i = 1 ; i <= m ; i++) {
			cin >> u >> v >> q;
			adj[u].push_back(ii(v , q));
			readj[v].push_back(ii(u , q));
		}
		dstart = disjktra(s , adj);
		dend = disjktra(t , readj);
		int ans = dstart[t];
		for (int i = 1 ; i <= k ; i++) {
			cin >> u >> v >> q;
			ans = min(ans , min(dstart[u] + q + dend[v] , dstart[v] + q + dend[u]));
		}
		cout << (ans == oo?-1:ans) << '\n';
	}


	return 0;
}
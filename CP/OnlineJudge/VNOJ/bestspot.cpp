#include <bits/stdc++.h>

using namespace std;
#define oo (int) (1e9 + 7)
#define ii pair<int ,int>

int P , n , C , tmp;
vector <int> favorite;
vector <ii> adj[507];

double dijkstra(int start) {
	vector <int> D(507);
	for (int i = 1 ; i <= P ; i++) 
		D[i] = oo;
	priority_queue<ii , vector<ii> , greater<ii>> pq;
	D[start] = 0;
	pq.push(ii(0 , start));
	while (!pq.empty()) {
		int u = pq.top().second , du = pq.top().first;
		pq.pop();
		for (ii v : adj[u]) {
			if (D[v.first] > du + v.second) {
				D[v.first] = du + v.second;
				pq.push(ii(D[v.first] , v.first));
			}
		}
	}
	double s = 0;
	for (auto e : favorite) {
		s += D[e];
	}
	return (double) (s / n);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> P >> n >> C;
	for (int i = 1 ; i <= n ; i++) {
		cin >> tmp;
		favorite.push_back(tmp);
	}
	int u , v , w;
	for (int i = 1 ; i <= C ; i++) {
		cin >> u >> v >> w;
		adj[u].push_back(ii(v , w));
		adj[v].push_back(ii(u , w));
	}
	sort(favorite.begin() , favorite.end());
	double maxi = DBL_MAX , tmp , ans;
	for (int i = 1 ; i <= P ; i++) {
		tmp = dijkstra(i);
		if (maxi > tmp) {
			maxi = tmp;	
			ans = i;
		}
	}
	cout << ans;
	return 0;
}
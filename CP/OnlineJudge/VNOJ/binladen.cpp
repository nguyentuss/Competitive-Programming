#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>

int m , n , x;

vector <ii> a[2225];
vector <ii> b[2225];
vector <ii> adj[44445];
vector <int> D(44445 , INT_MAX);

void Dijkstra(int start) {
	D[start] = 0;
	priority_queue<ii , vector<ii> , greater<ii>> pq;
	pq.push(ii(0 , 1));
	while (!pq.empty()) {
		int u = pq.top().second;
		int du = pq.top().first;
		pq.pop();
		ii go;
		for (auto go : adj[u]) {
			if (D[go.second] > du + go.first) {
				D[go.second] = du + go.first;
				pq.push(ii(D[go.second] , go.second));
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	//freopen("test.out","w",stdout);
	cin >> m >> n;
	bool change = false;
	int posa = 1 , posb = 1;
	int num = 1;
	for (int i = 1 ; i <= 2*m ;i++){
		for (int j = 1 ; j <= n ; j++) {
			num ++;
			cin >> x;
			if (!change) {
				a[posa].push_back(ii(x , num));
			}
			else {
				b[posb].push_back(ii(x , num));
			}
		}
		if (change == false) {
			change = true;
			posa ++;
			n --;
		}
		else {
			change = false;
			posb ++;
			n ++;
		}
	}
	ii go;
	for (int i = 0 ; i < (int) a[1].size() ; i++) a[0].push_back(ii(0 , 1));
	for (int i = 1 ; i <= m; i++) {
		for (int j = 0 ; j < (int) a[i].size() ; j++) {
			adj[a[i - 1][j].second].push_back(ii(a[i][j].first ,a[i][j].second));
			adj[a[i][j].second].push_back(ii(a[i - 1][j].first , a[i - 1][j].second));
		}
		for (int j = 0 ; j < (int) b[i].size() ; j ++) {
			adj[a[i][j].second].push_back(ii(b[i][j].first , b[i][j].second));
			adj[a[i][j + 1].second].push_back(ii(b[i][j].first , b[i][j].second));
			adj[b[i][j].second].push_back(ii(a[i][j].first , a[i][j].second));
			adj[b[i][j].second].push_back(ii(a[i][j + 1].first , a[i][j + 1].second));
			if (i + 1 <= m) {
				adj[b[i][j].second].push_back(ii(a[i+1][j].first,a[i+1][j].second));
				adj[b[i][j].second].push_back(ii(a[i+1][j+1].first,a[i+1][j+1].second));
				adj[a[i + 1][j].second].push_back(ii(b[i][j].first,b[i][j].second));
				adj[a[i + 1][j + 1].second].push_back(ii(b[i][j].first , b[i][j].second));
			}
			if (j + 1 < (int) b[i].size()) {
				adj[b[i][j].second].push_back(ii(b[i][j + 1].first,b[i][j+1].second));
				adj[b[i][j + 1].second].push_back(ii(b[i][j].first,b[i][j].second));
			}
		}
	}
	ii chay;
	/*for (int i = 1 ; i <= num ; i++) {
		for (auto chay : adj[i]) {
			cout << chay.first << " " << chay.second << '\n';
		}
		cout << '\n';
	}*/
	Dijkstra(1);
	cout << min(D[num] , D[num - (n - 1)]);
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long
#define MAX_N (ll) (1e3 + 7)
#define MAX_D (ll) (1e6 + 7)
#define ii pair<ll , ll>
#define x first
#define y second
#define inf (ll) (1e18)

ll n , m;
ll a[MAX_N][MAX_N];
map <ii ,bool> vis;
ll color[MAX_N][MAX_N];
ll dx[4] = {0 , 0 , 1 , -1};
ll dy[4] = {1 , -1 , 0 , 0};
vector <ii> adj[MAX_D];
ii val[MAX_D];
ll d[MAX_D];
ll cntnodes = 0;
queue<ii> q;
bool visited[MAX_N][MAX_N];

void BFS(ii start , ll nodes) {
	q.push(start);
	ll defaultcolor = a[start.x][start.y];
	visited[start.x][start.y] = true;
	color[start.x][start.y] = nodes;
	val[nodes].x = (defaultcolor == 1 ? 0 : defaultcolor);
	ll cnt = 1;
	while (!q.empty()) {
		ii u = q.front();
		q.pop();
		for (ll i = 0 ; i < 4 ; i++) {
			ii v = u;
			v.x += dx[i] , v.y += dy[i];
			if (v.x <= n && v.x >= 1 && v.y <= m && v.y >= 1 && !visited[v.x][v.y] && a[v.x][v.y] == defaultcolor) {
				visited[v.x][v.y] = true;
				color[v.x][v.y] = nodes;
				cnt ++;
				q.push(ii(v.x , v.y));
			}
		}
	}
	val[nodes].y = cnt;
	return;
}

void dijkstra() {
	for (int i = 1 ; i <= cntnodes ; i++) {
		d[i] = inf;
	}
	priority_queue<ii , vector<ii> , greater<ii>> pq;
	pq.push(ii(0 , 1));
	d[1] = 0;
	while (!pq.empty()) {
		ll u = pq.top().y;
		ll du = pq.top().x;
		pq.pop();
		if (du != d[u]) continue;
		for (int i = 0 ; i < adj[u].size() ; i++) {
			ll v = adj[u][i].y;
			ll uv = adj[u][i].x;
			if (d[v] > du + uv) {
				d[v] = du + uv;
				pq.push(ii(d[v] , v));
			}
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("vluoi.inp","r",stdin);
	//freopen("vluoi.out","w",stdout);
	cin >> n >> m;
	for (int i = 1 ; i <= n ;i++) {
		for (int j = 1 ; j <= m ; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1 ; i <= n ;i++) {
		for (int j = 1 ; j <= m ;j++) {
			if (!visited[i][j]) {
				cntnodes++;
				BFS(ii(i , j) , cntnodes);
			}
		}
	}
	
	for (int i = 1 ; i <= n ;i++) {
		for (int j = 1 ; j <= m ;j++) {
			for (int k = 0 ; k < 4 ; k++) {
				ii v = ii(i , j);
				v.x += dx[k] , v.y += dy[k];
				if (v.x <= n && v.x >= 1 && v.y <= m && v.y >= 1) {
					ll curr = color[i][j] , newc = color[v.x][v.y];
					if (!vis[ii(curr,newc)] && curr != newc){
						adj[curr].push_back(ii(val[newc].x*val[newc].y , newc));
						adj[newc].push_back(ii(val[curr].x*val[curr].y , curr));
						vis[ii(curr,newc)] = vis[ii(newc , curr)] = true;
					}
				}
			}
		}
	}

	dijkstra();
	cout << d[color[n][m]];
	return 0;
}
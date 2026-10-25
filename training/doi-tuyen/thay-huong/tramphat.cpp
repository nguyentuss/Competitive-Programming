#include <bits/stdc++.h>

using namespace std;

#define ii pair<double , double>
#define MAX_N (int) (1e3 + 7)
#define x first
#define y second
#define esp (double) (1e-7)

int n;
ii c[MAX_N];
bool visited[MAX_N];
vector<int> adj[MAX_N];

double distance(ii a , ii b) {
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y-b.y));
}


void DFS(int u) {
	visited[u] = true;
	for (auto v : adj[u]) {
		if (!visited[v]) DFS(v);
	}
}

bool check(double x) {
	for (int i = 1 ; i <= n ;i++) {
		adj[i].clear();
	}
	memset(visited , false , sizeof(visited));
	for (int i = 1 ; i <= n ;i++) {
		for (int j = i + 1 ; j <= n ; j++) {
			double dist = distance(c[i] , c[j]);
			if (dist <= 2*x + esp){
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
	DFS(1);
	for (int i = 1 ; i <= n ;i++) 
		if (!visited[i]) return false;
	return true;
}


int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("tramphat.inp","r",stdin);
	freopen("tramphat.out","w",stdout);
	cin >> n;
	for (int i = 1 ; i <= n ;i++) {
		double x , y; cin >> c[i].x >> c[i].y;
	}
	double l = 0 , r = 1e9 , ans = 0;
	//for (int i = 0 ; i < 200 ; i++) {
	while (r - l > esp) {
		double mid = (l + r)/2.0;
		if (check(mid)) {	
			r = mid;
			ans = mid;
		}
		else l = mid;
	}
	cout << fixed << setprecision(7) << ans;
	return 0;
}
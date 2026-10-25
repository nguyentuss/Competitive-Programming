#include <iostream>
#include <stdio.h>
#include <math.h>
#include <queue>

using namespace std;

#define MAX_N (int) (1e6 + 7)

int a[MAX_N];
int dist[MAX_N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	freopen("test.inp","r",stdin);
	int n , m; cin >> m >> n;;
	for (int i = 1 ; i <= n ; i++) {
		int u , v; cin >> u >> v;
		a[u] = v;
	}
	for (int i = 1; i <= m ; i++) {
		dist[i] = -1;
	}
	queue<int> q;
	q.push(1);
	dist[1] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		//if (u > m) continue;
		if (u == m) {
			cout << dist[m];
			return 0;
		}
		if (dist[a[u]] == -1 && dist[u] >= 0) {
			dist[a[u]] = dist[u];
			q.push(a[u]);
		}
		for (int i = 1 ; i <= 6 ; i++) {
			if (dist[u + i] == -1 && dist[u] >= 0) {
				dist[u + i] = dist[u] + 1;
				q.push(u + i);
			}
		}
	}
	return 0;
}
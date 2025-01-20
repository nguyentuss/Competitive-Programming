#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

int dist[20005];

int main(){ 
	boost;

	long long n , m; cin >> n >> m;

	memset(dist , -1 ,sizeof(dist));

	queue<long long> q;
	q.push(n);
	dist[n] = 0;
	while(!q.empty()) {
		long long u = q.front();
		long long v1 = q.front() * 2;
		long long v2 = q.front() - 1;
		q.pop();
		if (dist[v1] == -1 && v1 <= 20000) {
			dist[v1] = dist[u] + 1;
			q.push(v1);
		}
		if (dist[v2] == -1 && v2 > 0) {
			dist[v2] = dist[u] + 1;
			q.push(v2);
		}
		if (v1 == m) {
			cout << dist[v1];
			return 0;
		}
		else if (v2 == m) {
			cout << dist[v2];
			return 0;
		}

	}


	return 0;
}
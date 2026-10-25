#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

#define fi freopen("Dhoom4.inp","r",stdin);
#define fo freopen("Dhoom4.out","w",stdout);
#define mod (long long) 1e5
long long n , x , m , a;

vector <long long> key;
vector <long long> dist(1000000,-1);


int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	//fi;fo;
	cin >> n >> x >> m;
	for (long long i = 0 ; i < m ; i++) {
		cin >> a;
		key.push_back(a);
	}

	queue <long long> q;
	q.push(n);
	dist[n] = 0;
	while (!q.empty()){
		long long u = q.front();
		q.pop();
		for (long long i = 0 ; i < (long long) key.size() ; i++) {
			long long v = (u * key[i]) % 100000;
			if (dist[v] == -1) {
				dist[v] = dist[u] + 1;
				q.push(v);
				if (v == x) {
					cout << dist[v];
					return 0;
				}
			}  
		}
	}
	cout << -1;



	return 0;
}
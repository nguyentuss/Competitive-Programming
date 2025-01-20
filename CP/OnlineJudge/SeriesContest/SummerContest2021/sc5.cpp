#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <cmath>
#include <utility>

using namespace std;

#define inf (int) (1e9 + 7)
int n , m;
vector <vector <char>> adj(25 , vector <char> (25));
vector <vector <int>> dist(25 , vector <int> (25));
typedef pair <int , int> ii;

void init() {
	for (int i = 1 ; i <= n; i++) {
		for (int j = 1 ; j <= m ; j++){
			dist[i][j] = inf;
		}
	}
}


void calc() {
	queue <ii> q;
	q.push(ii(1,1));
	dist[1][1] = 0;
	while (!q.empty()) {
		int i = q.front().first;
		int j = q.front().second;
		q.pop();
		if (adj[i][j + 1] != '#' && j + 1 <= m) {
			if (adj[i][j + 1] == 'S' && 0 < dist[i][j + 1]) {
				dist[i][j + 1] = 0;
				q.push(ii(i , j + 1));
			}
			else if (adj[i][j + 1] == '.' && dist[i][j] < dist[i][j + 1]) {
				dist[i][j + 1] = dist[i][j];
				q.push(ii(i , j + 1));
			} 
			else 
				if (dist[i][j] + adj[i][j + 	1] - '0' < dist[i][j + 1] && adj[i][j + 1] >= '1' && adj[i][j + 1] <= '9'){
					dist[i][j + 1] = dist[i][j] + adj[i][j + 1] - '0';
					if (dist[i][j + 1] <= 9)
					q.push(ii(i , j + 1));
				}
		}
		if (adj[i][j - 1] != '#' && j - 1 > 0) {
			if (adj[i][j - 1] == 'S' && 0 < dist[i][j - 1]) {
				dist[i][j - 1] = 0;
				q.push(ii(i , j - 1));
			}
			else if (adj[i][j - 1] == '.' && dist[i][j] < dist[i][j - 1]) {
				dist[i][j - 1] = dist[i][j];
				q.push(ii(i , j - 1));
			}
			else 
				if (dist[i][j] + adj[i][j - 1] - '0' < dist[i][j - 1] && adj[i][j - 1] >= '1' && adj[i][j - 1] <= '9'){
					dist[i][j - 1] = dist[i][j] + adj[i][j - 1] - '0';
					if (dist[i][j - 1] <= 9) 
					q.push(ii(i , j - 1));
				}
		}
		if (adj[i + 1][j] != '#' && i + 1 <= n) {
			if (adj[i+1][j] == 'S' && 0 < dist[i + 1][j]) {
				dist[i+1][j] = 0;
				q.push(ii(i + 1 , j));
			}
			else if (adj[i+1][j] == '.' && dist[i][j] < dist[i+1][j]) {
				dist[i + 1][j] = dist[i][j];
				q.push(ii(i + 1 , j));
			}
			else 
				if (dist[i][j] + adj[i+1][j] - '0' < dist[i+1][j] && adj[i + 1][j] >= '1' && adj[i + 1][j] <= '9'){
					dist[i+1][j] = dist[i][j] + adj[i+1][j] - '0';
					if (dist[i + 1][j] <= 9)
					q.push(ii(i + 1 , j));
				}
		}
		if (adj[i-1][j] != '#' && i - 1 > 0) {
			if (adj[i-1][j] == 'S' && 0 < dist[i-1][j]) {
				dist[i - 1][j] = 0;
				q.push(ii(i - 1 , j));
			}
			else if (adj[i - 1][j] == '.' && dist[i][j] < dist[i-1][j]) {
				dist[i - 1][j] = dist[i][j];
				q.push(ii(i - 1 , j));
			}
			else 
				if (dist[i][j] + adj[i-1][j] - '0' < dist[i-1][j] && adj[i - 1][j] >= '1' && adj[i - 1][j] <= '9'){
					dist[i-1][j] = dist[i][j] + adj[i-1][j] - '0';
					if (dist[i - 1][j] <= 9)
					q.push(ii(i - 1 , j));
				}
		}
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	//freopen("sc5.inp","r",stdin);
	//freopen("sc5.out","w",stdout);
	int t; cin >> t;
	for (int test = 0 ; test < t ; test ++) {
		cin >> n >> m;
		init();
		for (int i = 1 ; i <= n; i++) 
			for (int j = 1 ; j <= m ; j++) 
				cin >> adj[i][j];
		calc();
		/*for (int i = 1 ; i <= n; i++){
			for (int j = 1 ; j <= m; j++) 
				cout << dist[i][j] << " ";
			cout << endl;
		}*/
		if (dist[n][m] < 10 && dist[n][m] != inf) cout << "possible" << endl;
		else cout << "impossible" << endl;
	}
	return 0;
}
#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cmath>
#include <vector>

#pragma GCC optimize("Ofast")

using namespace std;

#define MAX_N (int) (201)
#define MAX_M (int) (201)

struct segment
{
	int i , j;
};

int n ,m;
vector <vector <int>> adj(MAX_N , vector <int> (MAX_M));
int f[MAX_N][MAX_M][MAX_N];
int dist[MAX_N][MAX_M];
queue <segment> q;

void init() {
	for (int i = 1 ; i <= n; i++) 
		for (int j = 1 ; j <= m ; j++) 
			dist[i][j] = -1;
}

void loang(int i , int j , int si , int sj) {
	if (i > 0 && i <= n && j > 0 && j <= m) {
		dist[i][j] = max(dist[i][j] , dist[si][sj] + adj[i][j]);
		q.push({i , j});
	}
}


void calc() {
	init();
	q.push({1 , 1});
	dist[1][1] = 0;
	while (!q.empty()) {
		int i = q.front().i;
		int j = q.front().j;
		q.pop();
		loang(i , j + 1 , i , j);
		loang(i + 1 , j , i , j);
	}

}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++) 
		for (int j = 1 ; j <= m ; j++) {
			cin >> adj[i][j];
		}

	calc();
	for (int i = 1; i <= n ; i++) {
		for (int j = 1 ; j <= m ; j++){ 
			cout << dist[i][j] << " ";
		}
		cout << '\n';
	}

	return 0;
}
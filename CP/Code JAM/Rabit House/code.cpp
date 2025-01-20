#include <bits/stdc++.h>

using namespace std;

struct matrix {
	int i , j , val;
};
struct cmp {
	bool operator() (matrix &a , matrix &b) {
		return a.val < b.val;
	}
};

int n, m;
int maximum;
long long ans;
priority_queue <matrix , vector <matrix> , cmp> pq;
vector <vector <int>> adj(305 , vector <int> (305));
vector <vector <bool>> visit(305 , vector<bool> (305 , false));
 
void init() {
	maximum = -1;
	ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1 ; j <= m; j ++) {
			cin >> adj[i][j];
			visit[i][j] = false;
			//maximum = max(maximum , adj[i][j]);
		}
}
void loan(int i , int j , int val , int newi , int newj) {
	if (!visit[newi][newj] && val >= adj[newi][newj] && newi >= 1 && newi <= n && newj >= 1 && newj <= m) {
		ans += max(0 , val - adj[newi][newj] - 1);
		adj[newi][newj] = val - 1;
		visit[newi][newj] = true;
		pq.push({newi , newj , adj[newi][newj]});
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	int t; cin >> t;
	for (int test = 1 ; test <= t ; test ++) {
		cin >> n >> m;
		init();
		//cout << maximum;
		for (int i = 1 ; i <= n ; i++) 
			for (int j = 1 ; j <= m ; j++) 
				pq.push({i , j , adj[i][j]});

		while (!pq.empty()) {
			int i = pq.top().i , j = pq.top().j , val = pq.top().val; 
			visit[i][j] = true;
			pq.pop();
			loan(i , j , val , i - 1 , j);
			loan(i , j , val , i + 1 , j);
			loan(i , j , val , i , j - 1);
			loan(i , j , val , i , j + 1);
		}
		/*for (int i = 1 ; i <= n ; i++) {
			for (int j = 1 ; j <= m ; j++) 
				cout << adj[i][j] << " ";
			cout <<'\n';
		}*/
		cout << "Case #" << test << ": " << ans << '\n';
	}



	return 0;
}
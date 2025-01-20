#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("bfc23cedge.inp","r",stdin);
#define fo freopen("bfs23cedge.out","w",stdout);
#define maxn (int) 1e5 + 7

/*:3*/
vector <int> arr;
vector <int> v[maxn];
vector <int> paint;
vector <bool> visited(maxn,false);
int n , a , x , y;
int tomau = 1;

int dfs(){
	visited[1] = true;
	queue <int> q;	
	q.push(1);
	while (!q.empty()){
		int u = q.front(); q.pop();
			for (int i = 0 ; i < (int) v[u].size() ; i++) {
				bool check = false;
				if (!visited[i]) {
					if (paint[arr[i]])
					q.push(v[u][i]);
				} 
			}
	}



	return 0;
}

int main() {
	boost;
 	cin >> n;
	for (int i = 0 ; i < n - 1; i ++) {
		cin >> a;
		arr.push_back(a);
		x = a / 10;
		y = a % 10;
		v[x].push_back(y);
	}

	dfs();
	cout << tomau << endl;
	for (int i = 1 ; i < (int) paint.size() ; i++) cout << paint[i] << endl;


	return 0;
}
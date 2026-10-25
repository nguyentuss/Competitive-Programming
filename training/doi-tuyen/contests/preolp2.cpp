#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>

vector <ii> pos;
vector <char> a[60];
bool visited[60][60];
queue<ii> q;
char x;
int n , m;
long long ans = 0;

void init() {
	for (int i = 0 ; i < n ; i++) 
		for (int j = 0 ; j < m ; j++) 
			visited[i][j] = false;
	ans = 0;
	pos.clear();
	while (!q.empty()) q.pop();
	for (int i = 0 ; i <= 50 ; i++) a[i].clear();
}

void BFS(int startx , int starty) {
	q.push(ii(startx , starty));
	visited[startx][starty] = true;
	while (!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if ((x - 1 >= 0) && a[x - 1][y] == 'M' && visited[x - 1][y] == false) {
			q.push(ii(x - 1 , y));
			ans ++;
			visited[x - 1][y] = true;
		}
		if ((y - 1 >= 0) && a[x][y - 1] == 'M' && visited[x][y - 1] == false){
			q.push(ii(x , y - 1));
			ans ++;
			visited[x][y - 1] = true;
		}
		if ((x + 1 < n) && a[x + 1][y] == 'M' && visited[x + 1][y] == false) {
			q.push(ii(x + 1 , y));
			ans ++;
			visited[x + 1][y] = true;
		}
		if ((y + 1 < m) && a[x][y + 1] == 'M' && visited[x][y + 1] == false) {
			q.push(ii(x , y + 1));
			ans ++;
			visited[x][y + 1] = true;
		}
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	freopen("preolp2.inp","r",stdin);
	freopen("preolp2.out","w",stdout);
	int t; cin >> t;
	for (int test = 0 ; test < t ; test ++) {
		cin >> n >> m;
		init();
		for (int i = 0 ; i < n ; i++) {
			for (int j = 0 ; j < m ; j++) {
				cin >> x;
				a[i].push_back(x);
				if (x == 'E') pos.push_back(ii(i , j));
			}
		}
		for (int i = 0 ; i < (int) pos.size() ; i++) 
			BFS(pos[i].first , pos[i].second);
		cout << ans << endl;
	}


	return 0;
}
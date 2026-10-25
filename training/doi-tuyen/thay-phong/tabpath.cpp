#include <bits/stdc++.h>

using namespace std;

#define MAX_N (ll) (1e3 + 7) 
#define inf (ll) (1e9 + 7)
#define ii pair<ll ,ll>
#define f first
#define s second
#define ll long long

ll m , n , query;
char a[MAX_N][MAX_N];
ll visited[MAX_N][MAX_N];
deque<ii> q;
ll dx[] = {1 , - 1 , 0 , 0 };
ll dy[] = {0 , 0 , 1 , -1};

bool check(ll x , ll y){ 
    return (x >= 1 && x <= m && y >= 1 && y <= n); 
}


int main() {
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	cout.tie(NULL);
	freopen("TABPATH.inp","r",stdin);
	freopen("TABPATH.out","w",stdout);
	cin >> m >> n >> query;
	for (int i = 1 ; i <= m ; i++) {
		for (int j = 1 ; j <= n ; j++) {
			cin >> a[i][j];
			if (a[i][j] == '*') {
				q.push_back(ii(i , j));
				visited[i][j] = 0;
			}
			else visited[i][j] = inf;
		}
	}
	while (!q.empty()) {
		ii u = q.front();
		q.pop_front();
		for (ll i = 0 ; i < 4 ; i++) {
			ll x = u.f + dx[i];
			ll y = u.s + dy[i];
			if (check(x , y)) {
				if (a[x][y] == a[u.f][u.s] && visited[x][y] > visited[u.f][u.s]) {
					visited[x][y] = visited[u.f][u.s];
					q.push_front(ii(x , y));
				} 
				else if (visited[x][y] > (visited[u.f][u.s] + 1)) {
					visited[x][y] = visited[u.f][u.s] + 1;
					q.push_back(ii(x , y));
				}
			}
		}
	}
	for (int i = 1 ; i <= query ; i++) {
		ll x , y; cin >> x >> y;
		cout << visited[x][y] << '\n';
	}
	return 0;
}
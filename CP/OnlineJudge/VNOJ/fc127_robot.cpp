#include <bits/stdc++.h>

using namespace std;

#define ii pair <ll ,ll>
#define x first
#define y second
#define ll long long

ll n , m;
ll v[107][107];
bool vis[107][107];
ll upx[4] = {-1 , + 1 , 0 , 0};
ll upy[4] = {0 , 0 , -1 , +1};
vector <ii> tmp;
ll dis[107][107];
ll last , sizeeuler;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("inp.inp","r",stdin);
	//freopen("out.out","w",stdout);
	cin >> n >> m;
	for (ll i = 1; i <= n ; i++) {
		for (ll j = 1 ; j <= m ;j++) {
			cin >> v[i][j];
		}
	}
	long long k; cin >> k;
	queue<ii> q;
	q.push(ii(1 , 1));
	vis[1][1] = true;
	dis[1][1] = 1;
	tmp.push_back(ii(1 , 1));
	while (!q.empty()) {
		ll x = q.front().x;
		ll y = q.front().y;
		q.pop();
		ll newx = x + upx[v[x][y]];
		ll newy = y + upy[v[x][y]];
		if (newx > n || newy > m || newx <= 0 || newy <= 0) newx -= upx[v[x][y]] , newy -= upy[v[x][y]];
		if (!vis[newx][newy]) {
			vis[newx][newy] = true;	
			tmp.push_back(ii(newx , newy));
			dis[newx][newy] = tmp.size();
			q.push(ii(newx , newy));
		} 
		else {
			last = dis[newx][newy] - 1;
			sizeeuler = tmp.size() - last;
		}
	}
	if (k <= tmp.size()) cout << tmp[k].x << " " << tmp[k].y;
	else {
		cout << tmp[last + (k - last)%sizeeuler].x << " " << tmp[last + (k - last)%sizeeuler].y;
	}
	return 0;
}
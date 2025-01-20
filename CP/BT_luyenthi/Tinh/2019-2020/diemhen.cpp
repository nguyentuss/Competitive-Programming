#include <iostream>
#include <queue>
#include <vector>
#define ll long long
using namespace std;
 
const ll oo = 1e12;
#define maxn (ll) 1e5 +7
typedef pair<ll,ll> ii;
 
vector <ii> a[maxn];
 
ll d[maxn] , n , m ,d1[maxn] , dn[maxn] , binh[maxn] , an[maxn] , s ;
 
void dijkstra(ll s){
	priority_queue<ii , vector<ii> , greater<ii>> q;
 
	for (ll i = 1 ; i <= n ; i++)
		d[i] = oo;
 
	d[s] = 0;
	q.push(ii(0,s));
 
	while (!q.empty()){
		ll u = q.top().second;
		ll du = q.top().first;
		q.pop();
		if (du != d[u]) continue;
		for (ll i = 0 ; i < a[u].size();i++){
			ll v = a[u][i].second;
			ll uv = a[u][i].first;
			if (d[v] > du + uv){
				d[v] = du + uv;
				q.push(ii(d[v],v));
			} 
 
		}
	}
	for (ll i = 1 ; i <= n ; i++)
	{
		if (s == 1)
			d1[i] = d[i];
		else
			dn[i] = d[i];
	}
}
 
int	 main(){
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	//freopen("diemhen.inp","r",stdin);
	//freopen("diemhen.out","w",stdout);
	ll k , u , v , c; 
	cin >> n >> m >> k;
	for (ll i = 1 ; i <= m ; i++){
		cin >> u >> v >> c;
		a[u].push_back(ii(c,v));
		//a[v].push_back(ii(c,u));
	}
	for (ll i = 1 ; i <= k ; i++){
		cin >> binh[i] >> an[i];
	}
	dijkstra(1);
	dijkstra(n);
	for (ll i = 1 ; i <= k ; i++){
		s = d1[1] * binh[i] + dn[1]*an[i];
		for (ll j = 2 ; j <= n ; j++){
			s = min(s,d1[j]*binh[i] + dn[j]*an[i]);
		}
		cout << s << endl;	
	}
	return 0;
}
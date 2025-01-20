#include<bits/stdc++.h>
#include<algorithm>
#define ff first
#define ss second
#define pb push_back
#define bb begin
#define ee end
#define sz size
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>
#define bp __builtin_popcount
#define nex '\n'
typedef double dd;
using namespace std;

const int maxn = (1e5) + 10;
bool mark[maxn], rmark[maxn];
int a[maxn];
vector<int> adj[maxn], radj[maxn], comp[maxn];

vector<int> kos;
int n;

void dfs(int v){
	mark[v] = true;

	for(int u: adj[v]){
		if(!mark[u]) dfs(u);
	}

	kos.pb(v);
}

void sfd(int v, int root){
	rmark[v] = true;
	comp[root].pb(v);

	for(int u: radj[v]){
		if(!rmark[u]) sfd(u, root);
	}
}

void DEL(){
	for(int i = 0; i < n + 6; i++){
		mark[i] = rmark[i] = a[i] = 0;
		adj[i].clear();
		radj[i].clear();
		comp[i].clear();
	}
	kos.clear();
	n=0;
}

void SOLVE(){
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> a[i];

		int v = (i+a[i]+1) % n;
		if(v == 0)v = n;
		adj[i].pb(v);
		radj[v].pb(i);
	}
	

	for(int i = 1; i <= n; i++){
		if(!mark[i]){
			dfs(i);
		}
	}

	int id = 0;
	for(int i = n-1; i >= 0; i--){
		int v = kos[i];
		if(!rmark[v]){
			id++;
			sfd(v, id);
		}
	}
	

	int ans = 0;
	for(int i = 1; i <= id; i++){
		if(comp[i].sz() >= 2) ans += comp[i].sz();
		else if(adj[comp[i][0]][0] == comp[i][0]) ans++;
	}
	
	cout << ans << nex;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//cout << setprecision(10) << fixed;
	
	int t;
	cin >> t;

	while(t--){
		SOLVE();
		DEL();
	}
}
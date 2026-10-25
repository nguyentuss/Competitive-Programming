#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)
#define int long long
const int base = 500009;
#define ii pair<int , int>

int r1 , r2;
vector<int> adj1[MAX_N];
vector<int> adj2[MAX_N];
vector<int> v1 , v2;
int ti1[MAX_N] , ti2[MAX_N] , to1[MAX_N] , to2[MAX_N];
int d;
int POW[5*MAX_N];
int hashA[5*MAX_N + 7];
int hashB[5*MAX_N + 7];
int f1[5*MAX_N + 7];
int f2[5*MAX_N + 7];

void DFS1(int u , int father) {
	ti1[u] = ++d;
	v1.push_back(u);	
	for (auto v : adj1[u]) {
		if (v != father) {
			DFS1(v , u);
		}
	}
	to1[u] = ++d;
}

void DFS2(int u , int father) {
	ti2[u]=++d;
	v2.push_back(u);
	for (auto v : adj2[u]) {
		if (v != father) {
			DFS2(v , u);
		}
	}
	to2[u]=++d;
}

int get1(int l , int r) {
	return (hashA[r] - hashA[l - 1]*POW[r - l + 1]);
}

int get2(int l , int r) {
	return (hashB[r] - hashB[l - 1]*POW[r - l + 1]);
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	//freopen("test.out","w",stdout);
	int n ; cin >> n;
	POW[0] = 1;
	v1.push_back(0);
	v2.push_back(0);
	for (int i = 1 ; i < 5*MAX_N ; i++) 
		POW[i] = POW[i - 1]*base;
	cin >> r1;
	for (int i = 1 ; i < n ; i++) {
		int u , v ; cin >> u >> v;
		adj1[u].push_back(v);
		adj1[v].push_back(u);
	}
	cin >> r2;
	for (int i = 1 ; i < n ; i++) {
		int u , v; cin >> u >> v;
		adj2[u].push_back(v);
		adj2[v].push_back(u);
	}
	for (int i = 1 ; i <= n ; i++) {
		sort(adj1[i].begin() , adj1[i].end());
		sort(adj2[i].begin() , adj2[i].end());
	}
	d = 0;
	DFS1(r1 , -1);
	d = 0;
	DFS2(r2 , -1);
	string A , B;
	for (int i = 1 ; i < v1.size() ; i++)  
		A += to_string(v1[i]) , f1[i] = A.size();
	for (int i = 1 ; i < v2.size() ; i++) 
		B += to_string(v2[i]) , f2[i] = B.size();
	A = '0' + A , B = '0' + B;
	for (int i = 1 ; i < A.size() ; i++) {
		hashA[i] = hashA[i - 1]*base + A[i] - '0' + 1;
		hashB[i] = hashB[i - 1]*base + B[i] - '0' + 1;
	}
	map<ii , bool> cnt;
	for (int i = 1 ; i < v1.size() ; i++) {
		int num = (to1[v1[i]] - ti1[v1[i]] + 1)/2;
		//cout << v1[i] << " " << ti1[v1[i]] << " " << to1[v1[i]] << '\n'; 
		int r = i + num - 1;
		int tm = get1(f1[i - 1] + 1 , f1[r]);
		cnt[ii(num , tm)] = true;
	}
	//cout << '\n';
	int ans = 0;
	for (int i = 1 ; i < v2.size() ; i++) {
		int num = (to2[v2[i]] - ti2[v2[i]] + 1)/2;
		//cout << v2[i] << " " << ti2[v2[i]] << " " << to2[v2[i]] << '\n';
		int r = i + num - 1;
		if (cnt[ii(num , get2(f2[i - 1] + 1 , f2[r]))]) ans = max(ans , num);
	}
	cout << ans;
	return 0;
}
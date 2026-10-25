#include <bits/stdc++.h>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

int n , m , a , u , v , countplane;
long long w;
bool D[1000007];
vector <int> root(100007);

struct segment{
	int l , r ;
	long long val;
};

vector <segment> arr;

bool cmp(segment &a , segment &b) {
	return a.val < b.val;
}

void init() {
	for (int i = 1 ; i <= 100007 ; i++) 
		root[i] = i;
}
int findroot(int u) {
	if (u == root[u]) return u;
	else {
		root[u] = findroot(root[u]);
		return root[u];
	}
}
void unionset(int u , int v) {
	int rootu = findroot(u);
	int rootv = findroot(v);
	if (rootu != rootv) {
		root[root[u]] = rootv;
	}
}	

bool checking(int u , int v){
	int rootu = findroot(u);
	int rootv = findroot(v);
	if (rootu == rootv) return true;
	return false;
}

int main(){
	boost;
	freopen("kruskal.inp","r",stdin);
	freopen("kruskal.out","w",stdout);
	arr.clear();
	cin >> n >> m;
	for (int i = 0 ; i < m ; i++) {
		cin >> u >> v >> w;
		arr.push_back((segment) {u , v , w});
	}
	init();
	sort(arr.begin() , arr.end() , cmp);
	for (int i = 0 ; i < m ; i++) {	
		if (!checking(arr[i].l , arr[i].r)) {
			unionset(arr[i].l , arr[i].r);
			D[i] = true;
		}	
	} 
	int ans =0 ;
	for (int i = 0 ; i < m ; i++) {
		if (D[i]) {
			ans += arr[i].val;
			cout << arr[i].l << " " << arr[i].r << " " << arr[i].val << '\n';
		}
	}
	cout << ans;
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

//#pragma GCC optimize("Ofast")
int n , m , x , y , z;
vector <int> root(100007);

struct segment{
	int l , r , w , id ; 
};

bool cmp(segment &a , segment&b) {
	return a.w > b.w;
}

void init(){
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
	if (rootu != rootv) 
		root[root[u]] = rootv;

}

bool checking(int u , int v) {
	int rootu = findroot(u);
	int rootv = findroot(v);
	if (rootu == rootv) 
		return true;
	return false;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	freopen("ELECTRIC.inp","r",stdin);
	freopen("ELECTRIC.out","w",stdout);
	cin >> n >> m;

	vector <segment> arr; 
	for (int i = 0 ; i < m ; i++) {
		cin >> x >> y >> z;
		arr.push_back((segment) {x , y , z , i + 1});
		//arr.push_back((segment) {y , x , z , i + 1});
	}
	sort(arr.begin() , arr.end() , cmp);

	init();
	long long ans = 0;
	vector <int> go;
	for (int i= 0 ; i < m ; i++) {
		if (!checking(arr[i].l , arr[i].r)){
			unionset(arr[i].l , arr[i].r);
			go.push_back(arr[i].id);
			ans += arr[i].w;
		}
	}
	cout << ans << endl;
	sort(go.begin() , go.end());
	for (int i = 0 ; i < (int) go.size() ;i++) cout << go[i] << endl;
	return 0;
}
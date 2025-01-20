#include <bits/stdc++.h>

using namespace std;

int n , m ;
vector <int> root(100007);

struct element{
	int u , v , w;
};
bool cmp(element &a , element &b) {
	return a.w < b.w;
}

void init(){
	for (int i = 1 ; i <= 100000 ; i++) 
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
	ios::sync_with_stdio(0); cin.tie(NULL);

	vector <element> arr;
	int x , y , z; cin >> n >> m;
	for (int i = 0; i < m ; i ++) {
		cin >> x >> y >> z;
		arr.push_back((element) {x , y , z});
	}
	init();

	sort(arr.begin() , arr.end() , cmp);

	long long ans = 0;

	for (int i = 0 ; i < m ; i++) {
		if (!checking(arr[i].u , arr[i].v)) {
			unionset(arr[i].u , arr[i].v);
			ans += arr[i].w;
		} 
	}	

	cout << ans;

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

struct segment
{
	int l , r;
};

int num;
vector <int> root(100007);
vector <int> asknum;
vector <segment> arr;
map <int , bool> counted;
map <int , bool>::iterator it;


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
		num --;
		root[root[u]] = rootv;
	}
}	


int main(){
	boost;

	int n , m , u , v; cin >> n >> m;
	num = n;
	init();

	for (int i = 0 ; i < m ; i++) {
		cin >> u >> v;
		arr.push_back((segment) {u , v});
		//unionset(u , v);
	}

	int q , ask; cin >> q;

	for (int i = 1 ; i <= q; i ++) {
		cin >> ask;
		counted[ask - 1] = true;
		asknum.push_back(ask); 
	}

	for (int i = 0 ; i < m; i++) {
		if (!counted[i]) 
			unionset(arr[i].l , arr[i].r);
	}

	vector <int> ans(100007);
	for (int i = q - 1 ; i >= 0 ; i--) {
		ans[i] = num;
		unionset(arr[asknum[i]-1].l , arr[asknum[i]-1].r);
	}

	for (int i = 0 ; i < q ; i++) cout << ans[i] << " ";

	return 0;
}
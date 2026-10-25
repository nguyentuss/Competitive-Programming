#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <fstream>
#include <vector>
 
using namespace std;
 
#pragma GCC optimize("Ofast")
 
vector <int> root(1000007);
 
void init() {
	for (int i = 1 ; i <= 1000007 ; i++) {
		root[i] = i;
	}
}
 
int findroot(int x) {
	if (x == root[x]) return x;
	else {
		root[x] = findroot(root[x]);
		return root[x];
	}
}
 
void unionset(int u , int v) {
	int rootu = findroot(u);
	int rootv = findroot(v);
	if (rootu != rootv) {
		root[rootu] = rootv;
	}
}
bool checking(int u , int v) {
	int rootu = findroot(u);
	int rootv = findroot(v);
	if (rootu == rootv) return true;
	return false;
}
 
int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	int n , m , q; cin >> n >> m >> q;
	init();
	for (int i = 1 ; i <= m ; i++) {
		int u , v; cin >> u >> v;
		unionset(u , v);
	}
	for (int i = 0 ; i < q ; i++) {
		int u , v; cin >> u >> v;
		if (checking(u , v)) cout << "YES" << '\n';
		else cout << "NO" << '\n';	
	}
 
 
	return 0;
} 
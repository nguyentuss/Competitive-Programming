#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <fstream>
#include <vector>
 
using namespace std;
 
#pragma GCC optimize("Ofast")
 
vector <int> root(10001);
vector <int> len(10001); 

void init() {
	for (int i = 1 ; i <= 10000 ; i++) {
		root[i] = i;
		len[i] = 1;
	}
}
 
int findroot(int x) {
	if (x == root[x]) return x;
	else {
		root[x] = findroot(root[x]);
		return root[x];
	}
}
 
void unionset(int x , int y) {
	int u = findroot(x);
	int v = findroot(y);
	if (u != v) {
		if (len[u] < len[v]) swap(u , v);
		root[v] = u;
		if (len[u] == len[v]) len[u] += len[v];
	}
}
bool checking(int u , int v) {
	int rootu = findroot(u);
	int rootv = findroot(v);
	if (rootu == rootv) return true;
	return false;
}
 
int u , v , ask;
 
int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	int n; cin >> n;
	init();
	for (int i = 0 ; i < n ; i++) {
		cin >> u >> v >> ask;
		if (ask == 1) 
			unionset(u , v);
		else cout << checking(u , v) << endl;
	}
 	
	return 0;
} 
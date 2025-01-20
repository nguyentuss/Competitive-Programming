P#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7) 

vector <int> root(MAX_N + 7);
int n , m;

void clroot() {
	for (int i = 1 ; i <= MAX_N ; i++) 
		root[i] = i;
}

int findroot(int u) {
	if (root[u] == u) return u;
	else {
		root[u] = findroot(root[u]);
		return root[u];
	}
}

bool check(int u , int v) {
	int rootu = findroot(u) , rootv = findroot(v);
	if (rootu == rootv) return false;
	root[rootu] = rootv;
	return true;
}


struct edge {
	int u , v , id;
};

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while (t--) {
		clroot();
		cin >> n >> m;
		vector <int> a(n , 0) , b(n , 0);
		for (int i = 1 ; i < n ; i++) 
			cin >> a[i];
		for (int i = 1 ; i < n ; i++) 
			cin >> b[i];
		int u , v , id;
		vector <edge> compa , compb;
		for (int i = 1 ; i <= m ; i++) {
			cin >> u >> v >> id;
			if (id == 1) compa.push_back((edge){u , v , i});
			else compb.push_back((edge){u , v , i});
		}
		int maxa = 0 , maxb = 0;
		for (edge e: compa) 
			if (check(e.u , e.v)) maxa ++;
		clroot();
		for (edge e: compb) 
			if (check(e.u , e.v)) maxb ++;
		int mina = max(0 , n - 1 - maxb) , cost = 21e8 , pos = -1;
		for (int i = mina ; i <= maxa ; i++) {
			if (cost > a[i] + b[n - 1 - i]) {
				pos = i;
				cost = a[i] + b[n - 1 - i];
			}
		}	
		clroot();
		bitset <MAX_N> ans;
		for (edge e : compb) check(e.u , e.v);
		for (edge e : compa) ans[e.id] = check(e.u , e.v);
		clroot();
		for (edge e : compa) {
			if (ans[e.id]){ 
				check(e.u , e.v);
				pos --;
			}
		}		
		if (pos) {
			for (edge e: compa) {
				if (check(e.u , e.v)) { 
					ans[e.id] = true;
					pos --;
					if (pos == 0) break;
				}
			}
		} 
		for (edge e: compb) {
			if (check(e.u , e.v))
				ans[e.id] = true;
		}
		for (int i = 1 ; i <= m ; i++) {
			if (ans[i]) cout << i << " ";
		}
		cout << '\n';
	}

	return 0;
}
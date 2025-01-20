	#include <bits/stdc++.h>

	using namespace std;

	#define boost ios::sync_with_stdio(0); cin.tie(NULL);

	int n , u , v , ask;
	vector <int> root(10007);

	void init() {
		for (int i = 1 ; i <= 10000 ; i++) 
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
		//freopen("IOIBIN.inp","r",stdin);
		//freopen("IOIBIN.out","w",stdout);
		cin >> n;
		init();
		for (int i = 0 ; i < n ; i++) {
			cin >> u >> v >> ask;
			if (ask == 2) {
				if (checking(u , v)) cout << "1" << endl;
				else cout << "0" << endl;
			}
			else unionset(u ,v);	
			//for (int j = 1 ; j <= n ; j++) cout << root[j] << " ";
			//cout << endl;
		} 



		return 0;
	}
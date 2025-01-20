#include <bits/stdc++.h>

using namespace std;

vector <vector <int>> adj(200 , vector <int> (200));
set <int> s1 , s2;
int n;
int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);

	int t; cin >> t;
	for (int test = 1 ; test <= t ; test ++) {
		cin >> n;
		for (int i = 1 ; i <= n ; i++) 
			for (int j = 1 ; j <= n ; j++) {
				cin >> adj[i][j];
			}
		int k = 0 , r = 0 , c = 0;
		for (int i = 1 ; i <= n; i++) 
			k += adj[i][i];
		for (int i = 1 ; i <= n ; i++) {
			s1.clear(); s2.clear();
			for (int j = 1 ; j <= n ; j ++) {
				s1.insert(adj[i][j]);	
				s2.insert(adj[j][i]);
			}
			if ((int) s1.size() != n) k ++;
			if ((int) s2.size() != n) c ++;
		}
		cout << "Case #" << test << ": " << k << " " << r << " " << c << '\n';
	}

	return 0;
}
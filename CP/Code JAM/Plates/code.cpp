#include <bits/stdc++.h>

using namespace std;


int n , k , p;
vector <vector <int>> adj(5000 , vector<int> (5000));
vector<vector <int>> sum(5000 , vector<int> (5000));
vector<vector <int>> f(5000 , vector<int>(5000));

void init() {
	for (int i = 0 ; i <= n; i++) 
		for (int j = 0 ; j <= p ; j++) {
			f[i][j] = 0;
			sum[i][j] = 0;
		}
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= k ; j ++) { 
			cin >> adj[i][j];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(NULL);

	int t; cin >> t;
	for (int test = 1 ; test <= t ; test ++) {
		cin >> n >> k >> p;
		init();
		for (int i = 1 ; i <= n ; i++) {
			for (int j = 1 ; j <= k ; j++) {
				sum[i][j] = sum[i][j - 1] + adj[i][j];
			}
		}
		for (int i = 1 ; i <= n ; i++) {
			for (int j = 1 ; j <= p ; j ++) {
				for (int h = 0 ; h <= min(j , p) ; h ++) {
					f[i][j] = max(f[i][j] , sum[i][h] + f[i - 1][j - h]);
				}
			}
		}
		/*for (int i = 1 ; i <= n ; i++) {
			for (int j = 1 ; j <= p ; j++) 
				cout << f[i][j] << " ";
			cout << '\n';				
		}*/
		cout << "Case #" << test << ": " << f[n][p] << '\n';
	}

	return 0;
}
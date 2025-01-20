#include <bits/stdc++.h>

using namespace std;

int n , m;

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	//freopen("test.inp","r",stdin);
	//freopen("test.out","w",stdout);
	cin >> m >> n;
	vector <vector <int>> v(m + 1 , vector <int>(n + 1));
	for (int i = 1; i <= m ; i++) {
		for (int j = 1 ; j <= n; j++) {
			cin >> v[i][j];
		}
	}
	for (int i = 1 ; i <= m ; i++) 
		v[i][0] = v[i][1];
	vector <vector<int>> fone(n + 1 , vector<int> (m + 1));
	int ans = -1;
	for (int j = 1 ; j <= n ; j++) {
		vector <int> Lone(m + 2);
		vector <int> Rone(m + 2);
		vector <int> ONE(m + 2);
		deque <int> dqone;
		ONE[0] = -1 , ONE[m + 1] = -1; 
		for (int i = 1 ; i <= m; i++) {
			if (v[i][j - 1] != v[i][j]) {
				if (v[i][j - 1] == 0) 
					fone[j][i] = 1;
				else 
					fone[j][i] = 0;
			}		
			 else {
				if (v[i][j - 1] == 1)
					fone[j][i] = fone[j - 1][i] + 1;
			}
			ONE[i] = fone[j][i];
			cout << ONE[i] << " ";
		}
		cout << '\n';
		/*cout << "J = " << j << '\n';
		for (int i = 1 ; i <= m ; i++) cout << ONE[i] << " ";
		cout << '\n';
		for (int i = 1 ; i <= m ; i++) cout << ZERO[i] << " ";
		cout << '\n';*/

		dqone.push_back(0);
		for (int i = 1 ; i <= m ; i++) {
			while (dqone.size() && ONE[dqone.back()] >= ONE[i]) dqone.pop_back();
			Lone[i] = dqone.back() + 1;
			dqone.push_back(i);
		}
		while ((int) dqone.size()) dqone.pop_front();
		dqone.push_back(m + 1);
		for (int i = m ; i >= 1 ; i --) {
			while (dqone.size() && ONE[dqone.back()] >= ONE[i]) dqone.pop_back();
			Rone[i] = dqone.back() - 1;
			dqone.push_back(i);
		} 

		for (int i = 1 ; i <= m ; i++) {
			if (ONE[i] != 0) {
				//cout << i << " " << j << " " << ONE[i] << " " << Lone[i] << " " << Rone[i] << '\n';
				if (Rone[i] - Lone[i] + 1 >= 1)  
					ans = max(ans , ONE[i]*(Rone[i] - Lone[i] + 1));
			}
		}
	}
	cout << ans ;
	return 0;
}
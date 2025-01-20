#include <bits/stdc++.h>

using namespace std;

#define MOD (int) (1e9 + 7)

map<int ,bool> m;
int counted[1001];
int countedchange[1001];
vector <int> v , change;
int n , x , k;
int C[1001][1001];

void calc() {
	for (int i = 0 ; i <= 1000 ; i++) {
		C[i][0] = 1;
		C[i][i] = 1;
	}
	for (int i = 2 ; i <= 1000 ; i++) 
		for (int j = 1 ; j < i ; j++) {
			C[i][j] = (C[i - 1][j]%MOD + C[i - 1][j - 1]%MOD)%MOD;
		}
	return;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);

	calc();
	int t; cin >> t;
	while (t --) {
		v.clear(); change.clear(); m.clear();
		for (int i = 0 ; i <= 1000 ; i++) {
			counted[i] = 0;
			countedchange[i] = 0;
		}
		cin >> n >> k;
		for (int i = 0 ; i < n ; i++) {
			cin >> x;
			v.push_back(x);
		}
		sort(v.begin() , v.end() , greater<int>());
		for (int i = 0 ; i < k ; i++) {
			change.push_back(v[i]);
			m[v[i]] = true;
		}
		for (int i = 0 ; i < (int) v.size() ; i++) 
			if (m[v[i]] == true) 
				counted[v[i]] ++;
		for (int i = 0 ; i < (int) change.size() ; i++) 
			countedchange[change[i]] ++;
		long long ans = 1;
		for (int i = 0 ; i < (int) change.size() ; i++) {
			if (m[change[i]] == true) { 
				ans = (ans%MOD*C[counted[change[i]]][countedchange[change[i]]]%MOD)%MOD;
				m[change[i]] = false;
			}
		}
		cout << ans << '\n';

	}

	return 0;
}
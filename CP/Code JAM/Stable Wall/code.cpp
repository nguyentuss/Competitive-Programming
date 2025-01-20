#include <bits/stdc++.h>

using namespace std;

#define ngar ios::sync_with_stdio(0); cin.tie(NULL);

struct xy {
	int i , j;
};

map <char , bool> ngaaaaa;
map <char , bool>::iterator it;
vector <char> v;
vector <char> X(10);
vector <vector <bool>> visisted(100 , vector <bool> (100));
vector <vector <char>> adj(100 , vector <char> (100));
vector <xy> pos[100];
vector <bool> C(10 , false);
string ans;
bool correct;
int test;
int n , m;

void init() {
	v.clear();
	for (int i = 'A' ; i <= 'Z' ; i ++) 
		pos[i].clear();
	ngaaaaa.clear();
	for (int i = 0 ; i <= 10 ; i++) {
		C[i] = false;
		X[i] = ' ';
	}
	ans = "";
	correct = false;
	return;
}

void update(int a) {
	for (int i = 0 ; i < (int) pos[a].size() ; i++) {
		for (int j = pos[a][i].i ; j <= n ; j++) {
			if (visisted[j][pos[a][i].j] == true) break;
			else visisted[j][pos[a][i].j] = true;
		}
	}
}

void write() {
	for (int i = 1 ; i <= n; i++) {
		for (int j = 1 ; j <= m ; j++) {
			visisted[i][j] = false;
		}
	}
	for (int i = 1 ; i <= (int) v.size() ; i++) {
		for (int j = 0 ; j < (int) pos[X[i]].size() ; j ++) {
			int x = pos[X[i]][j].i , y = pos[X[i]][j].j;
			if (visisted[x][y] == true) return;
		}
		update(X[i]);
	}

	if (correct == false){
		for (int i = 1 ; i <= (int) v.size() ;i++) {
			ans += X[i];
		}
		cout << "Case #" << test << ": " <<  ans << '\n';
		correct = true;	
	}
	return;
}

void ngasiucute(int i) {
	for (int j = 0 ; j < (int) v.size() ;  j++) {
		if (C[j] == false) {
			//if ((int) v.size() == 5) cout << 1;
			X[i] = v[j];
			C[j] = true;
			if (i == (int) v.size()) write();
			else ngasiucute(i + 1);
			if (correct) return;
			C[j] = false;
		}
	}
	return;
}

int main(){
	ngar;
	int t; cin >> t;
	for (int ngarcute = 1 ; ngarcute <= t ; ngarcute ++) {
		cin >> n >> m;
		init();
		for (int i = 1 ; i <= n ; i++) {
			for (int j = 1 ; j <= m ; j++) {
				cin >> adj[i][j];
				ngaaaaa[adj[i][j]] = true;
				pos[adj[i][j]].push_back({i , j});
			}
		}
		for (it = ngaaaaa.begin() ; it != ngaaaaa.end() ; it ++) {
			v.push_back(it -> first);
		}
		//for (int i = 0 ; i < (int) v.size() ;i++) cout << v[i] << " ";
		test = ngarcute;
		ngasiucute(1);
		if (!correct) cout << "Case #" << ngarcute << ": " << -1 << '\n';
	}

	return 0;
}
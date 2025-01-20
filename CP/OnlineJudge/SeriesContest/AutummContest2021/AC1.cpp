#include <bits/stdc++.h>

using namespace std;

string a , b , t;
int T;
int cntT[257] , cntA[257] , n , miss[257] , X[80] , tmp[257];
int m[257];
bool check = false;
vector <int> pos;
int cnt = 0;

void init() {
	for (int i = 1 ; i <= 256 ; i++) {
		cntT[i] = 0;
		cntA[i] = 0;
		miss[i] = 0;
	}
	pos.clear();
}

void process() {
	for (int i = 'A' ; i <= 'Z' ; i++) m[i] = 0;
	for (int i = 0 ; i < n ; i ++) {
		if (X[i]) 
			m[b[pos[i]]]++;
		else 
			m[a[pos[i]]]++;
	}
	for (int i = 0 ; i < t.size() ; i++) {
		if (m[t[i]] < miss[t[i]]) 
			return;
	}
	/*for (int i = 0 ; i < n ; i++) {
		if (X[i]) cout << b[pos[i]];
		else cout << a[pos[i]];
	}*/
	check = true;
}

void backtr(int i) {
	for (int j = 0 ; j <= 1 ; j++) {
		X[i] = j;
		if (i == n - 1) process();
		else backtr(i + 1);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	//freopen("test.inp","r",stdin);
	//freopen("test.out","w",stdout);
	cin >> T;
	while (T--) {
		init();
		cin >> a >> b >> t;
		int lent = t.size();
		for (int i = 0 ; i < lent ; i ++) 
			cntT[t[i]] ++;
		for (int i = 0 ; i < a.size() ; i++) {
			if (cntT[a[i]] && cntT[b[i]]) 
				pos.push_back(i);
			else if (cntT[a[i]]) cntA[a[i]] ++;
			else if (cntT[b[i]]) cntA[b[i]] ++;
		}
		for (int i = 0 ; i < lent ; i ++) {
			miss[t[i]] = max(0 , cntT[t[i]] - cntA[t[i]]);
			//cout << t[i] << " " << cntT[t[i]] - cntA[t[i]] << '\n'; 
		}
		n = pos.size();
		//for (int i = 0 ; i < pos.size() ; i++) cout << pos[i] << " ";
		if (n) 	
		{
			bool kt = true;
			for (int i = 0 ; i < lent ; i++) {
				if (cntT[t[i]] > cntA[t[i]]) {
					kt = false;
					break; 
				}
			}
			if (kt) cout << "YES" << '\n';
			else {
				backtr(0);
				if (check) cout << "YES" << '\n';
				else cout << "NO" << '\n';
			}
		}
		else {
			bool kt = true;
			for (int i = 0 ; i < lent ; i++) {
				if (cntT[t[i]] > cntA[t[i]]) {
					cout << "NO" << '\n';
					kt = false;
					break;
				} 
 			}
 			if (kt) cout << "YES" << '\n';
		}
	}
	return 0;
}
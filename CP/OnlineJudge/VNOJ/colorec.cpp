#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast")

int color[401][401] , u , v , c;
vector <vector<int>> counted(5 , vector<int> (5));

void init() {
	for (int i = 1 ; i <= 4 ; i ++) {
		for (int j = 1 ; j <= 4 ; j++) {
			counted[i][j] = 0;
		}
	}
	return;
}

long long calc() {
	long long x = 0;
	for (int a = 1 ; a <= 4 ; a++)
		for (int b = 1 ; b <= 4 ; b ++) 
			for (int c = 1 ; c <= 4 ; c++) 
				for (int d = 1 ; d <= 4 ; d++) 
					if (a != b && a != c && a != d && b != c && b != d && c != d) {
						x += counted[a][b]*counted[c][d];
					}

	return x;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	for (int i = 0 ; i < n ; i++) {
		cin >> u >> v >> c;
		color[v+200][u+200] = c;
	}
	//cout << color[202][199];
	long long ans = 0;
	for (int i = 0 ; i <= 400 ; i++) {
		for (int j = i + 1 ; j <= 400 ; j++) {
			init();
			for (int k = 0 ; k <= 400 ; k++) {
				if (color[i][k] > 0 && color[j][k] > 0){
					counted[color[i][k]][color[j][k]]++;
					//counted[color[j][k]][color[i][k]]++;
				}
			}
			ans += calc();
		}
	}
	cout << ans/2;
	return 0;
}
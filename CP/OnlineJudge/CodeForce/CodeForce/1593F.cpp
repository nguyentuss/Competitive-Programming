#include <bits/stdc++.h>

using namespace std;

struct seg {
	int i , j , numA , numB;
	char x;
};

int f[42][42][42][42];
seg trace[42][42][42][42];
char res[42];
int n;


void init() {
	for (int i = 0 ; i <= 40 ; i++) {
		for (int j = 0 ; j <= 40 ; j++) {
			for (int numA = 0 ; numA <= 40 ; numA++) {
				for (int numB = 0 ; numB <= 40 ; numB++) {
					f[i][j][numA][numB] = 0;
				}
			}
		}
	}
	return;
}

bool DFS(int i , int j , int numA , int numB) {
	if (i == 0 && j == 0 && numA == 0 && numB == 0) 
		return true;
	if (!f[i][j][numA][numB]) return false;
	seg tmp = trace[i][j][numA][numB];
	res[i] = tmp.x;
	return DFS(tmp.i , tmp.j , tmp.numA , tmp.numB);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	int t; cin >> t;
	while (t--) {
		init();
		int A , B;
		cin >> n >> A >> B;
		string N; cin >> N;
		f[0][0][0][0] = 1;
		for (int i = 0 ; i < n ; i++) {
			for (int j = 0 ; j <= n ; j++) {
				for (int numA = 0 ; numA <= A ; numA++) {
					for (int numB = 0 ; numB <= B ; numB++) {
						if (!f[i][j][numA][numB]) 
							continue;
						f[i + 1][j + 1][(numA*10 + N[i] - '0')%A][numB] = 1;
						f[i + 1][j][numA][(numB*10 + N[i] - '0')%B] = 1;
						if (j + 1 <= n) 
							trace[i + 1][j + 1][(numA*10 + N[i] - '0')%A][numB] = {i , j , numA , numB , 'R'};
						trace[i + 1][j][numA][(numB*10 + N[i] - '0')%B] = {i , j , numA , numB , 'B'};
					}
				}
			}
		}
		int ans = INT_MAX;
		bool found = false;
		for (int i = 1 ; i < n ; i++) {
			if (f[n][i][0][0] && abs(i - (n - i)) < ans) {
				ans = abs(i - (n - i));
				found = true;
				DFS(n , i , 0 , 0);
			}
		}
		if (!found) cout << -1 << '\n';
		else {
			for (int j = 1 ; j <= n ; j++) cout << res[j];
				cout << '\n';
		}
	}
	return 0;
}
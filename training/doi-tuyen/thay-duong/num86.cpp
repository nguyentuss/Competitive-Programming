#include <bits/stdc++.h>

using namespace std;

#define MAX_N (207)
#define ii pair<int ,int> 
#define f first
#define s second

int n;
int F[MAX_N][MAX_N];
vector <int> POW(1000);


void DFS() {
	for (int i = 0 ; i <= 200 ; i++) {
		for (int j = 0 ; j <= 200 ; j++) {
			F[i][j] = -1;
		}
	}
	POW[0] = 1;
	for (int i = 1 ; i <= 200 ; i++) POW[i] = (POW[i - 1]*10)%n;
	F[1][0] = 6%n;
	F[0][1] = 8%n;
	queue <ii> q;
	q.push(ii(1 , 0));
	q.push(ii(0 , 1));
	while (!q.empty()) {
		int x = q.front().f , y = q.front().s;
		q.pop();
		if (!F[x][y]) {
			for (int i = 1 ; i <= y ; i++) cout << 8;
			for (int i = 1 ; i <= x ; i++) cout << 6;
			return;
		}
		if (x + y >= 200) continue;
		if (F[x + 1][y] == -1) {
			F[x + 1][y] = (F[x][y]*10%n + 6%n)%n;
			q.push(ii(x + 1 , y));
		}
		if (F[x][y + 1] == -1) {
			F[x][y + 1] = (F[x][y]%n + POW[x + y]*8%n)%n;
			q.push(ii(x , y + 1));
		}
	}
	cout << -1;
}

int main() { 
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("num86.inp","r",stdin);
	freopen("num86.out","w",stdout);
	cin >> n;
	DFS();

	return 0;
}
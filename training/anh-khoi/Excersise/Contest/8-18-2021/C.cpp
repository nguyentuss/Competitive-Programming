#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)

int n , q;
int P[MAX_N][20];
int H[MAX_N];
vector <int> adj[MAX_N];

void DFS(int u , int father) {
	P[u][0] = father;
	for (int i = 0 ; i < (int) adj[u].size() ;i++) {
		int v = adj[u][i];
		if (v == father) {
			continue;
		}
		H[v] = H[u] + 1;
		DFS(v , u);
	}
}

void buildtable() {
	for (int u = 1 ; u <= n ; u++) {
		for (int k = 1 ; k < 20 ; k ++) {
			P[u][k] = -1;
		}
	}
	for (int k = 1 ; k < 20 ;k++) {
		for (int u = 1 ; u <= n ; u++) {
			if (P[u][k - 1] != -1){
				P[u][k] = P[P[u][k - 1]][k - 1];
			}
		}
	}
}
int LCA(int u , int v) {
	if (H[u] < H[v]) {
		swap(u , v);
	}
	while (H[u] > H[v]) {
		for (int k = 19 ; k >= 0 ; k --) {
			if (P[u][k] != -1 && H[P[u][k]] >= H[v]) {
				u = P[u][k];
				break;
			}
		}
	}	
	if (u == v) return u;
	while (true) {
		bool found = false;
		for (int k = 19 ; k >= 0 ; k --) {
			if (P[u][k] != 1 && P[v][k] != -1  && P[u][k] != P[v][k]) {
				u = P[u][k];
				v = P[v][k];
				found = true;
				break;
			}
		}
		if (!found) {
			break;
		}
	}
	return P[u][0];
}

int getres(int a , int b) {
	int tmp = LCA(a , b);
	return H[a] + H[b] - 2*H[tmp] + 1;
}

int cong(int a , int b , int c) {
	return (a + b - c + 1)/2;
}

int calc(int a , int b , int c) {
	int tmp1 = getres(a , b);
	int tmp2 = getres(b , c);
	int tmp3 = getres(a , c);
	//cout << tmp1 << " " << tmp2 << " " << tmp3 << '\n';
	//cout << cong(tmp1 , tmp2 , tmp3);
	int res = max(cong(tmp1 , tmp2 , tmp3) , max(cong(tmp2 , tmp3 , tmp1) , cong(tmp1 , tmp3 , tmp2)));
	return res;
}

int main() {
	ios::sync_with_stdio(0);cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> q;
	for (int i = 2 ; i <= n ; i++) {
		int x; cin >> x;
		adj[i].push_back(x);
		adj[x].push_back(i);
	}
	DFS(1 , -1);
	H[1] = 0;
	buildtable();
	for (int i = 1 ; i <= q ; i++) {
		int a , b , c; cin >> a >> b >> c;
		cout << calc(a , b , c) << '\n';
	}
	return 0;
}
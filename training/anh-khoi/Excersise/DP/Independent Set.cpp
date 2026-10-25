#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N (int) (1e5 + 7)
#define mod (int) (1e9 + 7)

int n , x , y; 
vector <int> arr[MAX_N];
long long f[MAX_N][2];

void DFS(int u , int father) {
	if ((int) arr[u].size() == 1 && father != -1) {
		f[u][0] = 1;
		f[u][1] = 1;
		return;
	}
	long long mul0 = 1 , mul1 = 1;
	for (int i = 0 ; i < (int) arr[u].size() ; i++) {
		int v = arr[u][i];
		if (v == father) continue;
		DFS(v , u);
		mul0 = (mul0*(f[v][0] + f[v][1]))%mod;
		mul1 = (mul1*f[v][0])%mod;
	}
	f[u][0] = mul0;
	f[u][1] = mul1;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	//freopen("Independent Set.inp","r",stdin);
	cin >> n;
	for (int i = 0 ; i < n - 1 ; i++){
		cin >> x >> y;
		//cout << x << " " << y << endl;
		arr[x].push_back(y);
		arr[y].push_back(x);
	}
	//for (int i = 1 ; i <= n ; i++) cout << arr[i].size() << " ";
	DFS(1 , -1);
	cout << (f[1][0] + f[1][1])%mod;
	return 0;
}
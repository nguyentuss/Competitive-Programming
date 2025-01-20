#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define INF (int) 1e9 + 7
#define fi freopen("727A.inp","r",stdin);
#define fo freopen("727A.out","w",stdout);

vector <bool> visited(INF);
vector <long long> ans;
long long a , b , c;
bool checking = false;

void DFS(long long u) {
	visited[u] = true;
	if (checking) ans.push_back(u);
	if (u == b) {
		ans.push_back(u);
		checking = true;
		c = b;
		return;
	}
	if (u > b) return;

	if (!visited[u * 2]) DFS(u * 2);
	if (!visited[u * 10 + 1]) DFS(u * 10 + 1);
}

int main(){
	boost;
	fi;fo;
	cin >> a >> b;

	DFS(a);

	if (checking) cout << "YES";
	else cout << "NO";

	for (int i = 0 ; i < (int) ans.size() ; i++) cout << ans[i] << " ";

	return 0;
}
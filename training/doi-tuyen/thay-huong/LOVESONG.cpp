#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)
#define ii pair<int ,int>

int a[MAX_N] , b[MAX_N];
bool check[MAX_N];
vector<ii> ans;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("lovesong.inp","r",stdin);
	freopen("lovesong.out","w",stdout);
	int n , m ; cin >> n >> m;
	for (int i = 1 ; i <= n ; i++) cin >> a[i];
	for (int i = 1 ; i <= m ; i++) cin >> b[i];
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= m ; j++) {
			if (!check[j] && a[i] != b[j]) {
				ans.push_back(ii(i , j));
				check[j] = true;
				break;
			}
		}
	}
	cout << ans.size() << '\n';
	for (auto e : ans) cout << e.first << " " << e.second << '\n';
	return 0;
}
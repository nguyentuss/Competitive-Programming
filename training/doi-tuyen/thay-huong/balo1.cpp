#include <bits/stdc++.h>

using namespace std;
int n , m;
int dp[2008][2008];
int pre[2008][2008];
vector <int> v(2008);

typedef pair<int , int> ii;

void init(){
	for (int i = 1 ; i <= m ; i++)
		for (int j = 1 ; j <= n ; j++) {
			dp[i][j] = 0;
			pre[i][j] = v[i - 1];
		}
}
int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	freopen("balo1.inp","r",stdin);
	freopen("balo1.out","w",stdout);
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++) 
		cin >> v[i];
	v[0] = 0;
	init();
	for (int choose = 1 ; choose <= n ; choose++)
		for (int weigth = 1 ; weigth <= m ; weigth++) { 
			if (v[choose] > weigth) {
				dp[choose][weigth] = dp[choose - 1][weigth];
			}
			else {
				dp[choose][weigth] = max(dp[choose - 1][weigth] , dp[choose - 1][weigth - v[choose]] + v[choose]);
			}
		}
	/*for (int i = 1 ; i <= n; i++){
		for (int j = 1 ; j <= m ; j++)
			cout << dp[i][j] << " ";
		cout << endl;
	}*/
	cout <<dp[n][m] << endl;
	queue <ii> q;
	int i , j;
	q.push(ii(n , m));
	vector <int> arr;
	while(!q.empty() && (i != 0 || j != 0)) {
		i = q.front().first; 
		j = q.front().second;
		q.pop();
		if (dp[i][j] != dp[i - 1][j] && ((i != 0) || (j != 0))) {
			arr.push_back(v[i]);
			q.push(ii(i - 1 , dp[i][j] - v[i]));
		}
		else if (dp[i][j] == dp[i-1][j]) q.push(ii(i - 1 , j));
	}
	reverse(arr.begin() , arr.end());
	for (int i = 0 ; i < (int) arr.size() ; i++) 
		cout << arr[i] << " ";
	return 0;
}
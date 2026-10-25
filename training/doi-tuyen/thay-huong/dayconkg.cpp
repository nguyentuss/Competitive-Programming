#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast")

vector <int> v((int) (1e4 + 7));
vector <int> write;
int n , x;
vector <int> dp(((int) 1e4 + 7),1);
vector <int> father((int) 1e4 + 7);

int main(){
	freopen("dayconkg.inp","r",stdin);
	freopen("dayconkg.out","w",stdout);
	cin >> n;
	for (int i = 1 ; i <= n; i++) 
		cin >> v[i];
		
	dp[0] = 0;
	for (int i = 1 ; i <= n; i++){
		for (int j = i - 1 ; j >= 1 ; j--) {
			if (v[i] >= v[j] && dp[i] <= dp[j] + 1) {
				dp[i] = dp[j] + 1;
				father[i] = v[j];
			}
		}
	}
	int ans = -1 , pos;
	for (int i = 1 ; i <= n ; i++){
		//cout << dp[i] << " "; 
		if (ans < dp[i]) {
			ans = dp[i];
			pos = i;
		}
	}
	cout << ans;
	cout << endl;
	int son = father[pos];
	write.push_back(v[pos]);
	for (int i = pos - 1; i >= 1 ; i--) {
		if (son == v[i]) {
			write.push_back(v[i]);
			son = father[i];
		}

	}
	reverse(write.begin() , write.end());
	for (int i = 0 ; i < (int) write.size() ; i++) {
		//if (i == (int) write.size() - 1) cout << write[i];
		/*else*/ cout << write[i] << " ";
	}
	for (int i = 1 ; i <= n ; i++) cout << father[i] << " ";

	return 0;
}
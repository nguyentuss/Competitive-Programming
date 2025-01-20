#include <iostream>
#include <string> 

using namespace std;

int len;
string s[100005];
string c[100005];
string ans;

int main(){	
	ios::sync_with_stdio(0); cin.tie(NULL);
	int n; cin >> n;
	for (int i = 1 ; i <= n ; i++) {
		cin >> len >> s[i];
	}
	int ask;
	for (int i = 1 ; i <= n ; i++) {
		cin >> ask;
		c[ask] += s[i];	
	}
	int q;
	for (int i = 1 ; i <= n; i++) ans += c[i];
	cin >> q;
	int u , v;
	for (int i = 0 ; i < q ; i++) {
		cin >> u >> v;
		char temp = ans[u - 1];
		ans[u - 1] = ans[v - 1];
		ans[v - 1] = temp;
		//cout << ans << endl;
	}

	cout << ans;

	return 0;
}
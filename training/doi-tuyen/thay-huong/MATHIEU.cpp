#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (2*1e6 + 7) 

string s;
int v[MAX_N] , f[MAX_N] , n , m;
vector<char> status[MAX_N];
int cnt[MAX_N];

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("MATHIEU.inp","r",stdin);
	freopen("MATHIEU.out","w",stdout);
	cin >> s;
	n = s.size();
	s = '0' + s;
	cin >> m;
	for (int i = 1 ; i <= m ; i++) {
		int x; cin >> x;
		f[x] ++ , f[(n - x + 1) + 1]--;
	}
	for (int i = 1 ; i <= n ; i++) {
		f[i] += f[i - 1];
		v[i] += f[i];
	}
	for (int i = 1 ; i <= n ; i++) 
		status[v[i]].push_back(s[i]);
	for (int i = 1 ; i <= m ; i+=2){ 
		reverse(status[i].begin() , status[i].end());
	}
	for (int i = 1 ; i <= n ; i++) {
		cout << status[v[i]][cnt[v[i]]++];
	}
	return 0;
}
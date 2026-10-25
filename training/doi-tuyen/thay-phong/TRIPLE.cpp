#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (107)
#define ii pair<int ,int>
#define f first
#define s second
#define int long long

char A[MAX_N][MAX_N];
vector<ii> v;

bool check(ii a , ii b , ii c) {
	return (((b.f - a.f)*(c.s - a.s) - (b.s - a.s)*(c.f - a.f)) == 0);
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	int n; cin >> n;
	v.push_back(ii(0 , 0));
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1; j <= n ; j++) {
			cin >> A[i][j];
			if (A[i][j] >= 'A' && A[i][j] <= 'Z') 
				v.push_back(ii(i , j));
		}
	}
	int ans = 0;
	for (int i = 1 ; i < v.size() ; i++) {
		for (int j = i + 1 ; j < v.size() ; j ++) {
			for (int k = j + 1 ; k < v.size() ; k++) {
				if (check(v[i] , v[j] , v[k])) {	
					ans ++;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
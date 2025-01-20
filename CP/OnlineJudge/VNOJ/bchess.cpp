#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#define ii pair<int ,int>
#define f first
#define s second

int F[2003][2003] , G[2003][2003];
char A[2003][2003];
ii ans[3];

void update(int val , int &ans , int &cnt){
	if (val > ans) {
		ans = val;
		cnt = 1;
	}
	else if (val == ans) cnt ++;
	return;
}

int main(){ 
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;	
	for (int i = 1 ; i <= n; i ++) {
		for (int j = 1 ; j <= n ;j ++) {
			cin >> A[i][j];
			if (A[i][j] == '1') {
				F[i][j] = 0;
				G[i][j] = min(G[i - 1][j - 1] , min(F[i - 1][j] , F[i][j - 1])) + 1;
				update(G[i][j] - 1 + G[i][j]%2 , ans[1].f , ans[1].s);
				update(G[i][j] - G[i][j]%2 , ans[0].f , ans[0].s);
			}
			else {
				G[i][j] = 0;
				F[i][j] = min(F[i - 1][j - 1] , min(G[i - 1][j] , G[i][j - 1])) + 1;
				update(F[i][j] - 1 + F[i][j]%2 , ans[2].f , ans[2].s);
				update(F[i][j] - F[i][j]%2 , ans[0].f , ans[0].s);
			}
		}
	}
	for (int i = 0 ; i < 3 ; i++) {
		cout << ans[i].f << " " << ans[i].s << '\n';
	}
	return 0;
}
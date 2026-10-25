#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e6 + 7)
#define inf (int) (1e9 + 7)
#define int long long

deque <int> dq;
int n , x;
int L[MAX_N] , R[MAX_N];
int v[MAX_N];
int cnt[MAX_N];

void calc() {
	for (int i = 0 ; i <= n ; i++) {
		R[i] = 0;
		L[i] = 0;
	}
	v[0] = v[n + 1] = n + 1;
	dq.clear();
	dq.push_back(0);
	for (int i = 1; i <= n; i++) {
	    while (dq.size() && v[dq.back()] < v[i]) dq.pop_back();
	    if (dq.size()) dq.back();
	    L[i] = dq.back() + 1;
	    dq.push_back(i);
	}
	dq.clear();
	dq.push_back(n + 1);
	for (int i = n ; i >= 1 ; i --) {
		while (dq.size() && v[dq.back()] < v[i]) dq.pop_back();
		R[i] = dq.back() - 1;
		dq.push_back(i);
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	//freopen("pair2max.inp","r",stdin);
	//freopen("pair2max.out","w",stdout);
	cin >> n;
	for (int i = 1 ; i <= n ; i++) {
		cin >> v[i];
	}
	calc();
	/*for (int i = 1 ; i <= n ; i++) {
		cout << L[i] << " " << R[i] << '\n';
	}*/
	int ans = 0;
	for (int i = 1 ; i <= n ; i++) {
		ans += cnt[i - 1];
		cnt[R[i]] ++;
	}
	memset(cnt , 0 , sizeof cnt);
	reverse(v + 1 , v + 1 + n);
	calc();
	for (int i = 1 ; i <= n ; i++) {
		ans += cnt[i - 1];
		//cout << ans << " ";
		cnt[R[i]]++;
	}
	cout << ans;

	return 0;
}

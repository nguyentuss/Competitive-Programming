#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (2e5 + 7)
#define int long long

struct coordinates {
	int x1 , y1 , x2 , y2;
};

coordinates convert(int x , int y , int p) {
	coordinates tmp = {x - p , y - p , x + p , y + p};
	return tmp;
}

int x[MAX_N] , y[MAX_N] , P[MAX_N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("giaohang.inp","r",stdin);
	freopen("giaohang.out","w",stdout);
	int n; cin >> n;
	for (int i = 1 ; i <= n ; i++) {
		cin >> x[i] >> y[i] >> P[i];
	}
	coordinates A , S;
	int ans = 0;
	A = convert(x[1] , y[1] , P[1]);
	//cout << A.x1 << " " << A.y1 << " " << A.x2 << " " << A.y2;
	for (int i = 2 ; i <= n ; i++) {
		S = convert(x[i] , y[i] , P[i]);
		int d = max( max(S.x1 - A.x2, A.x1 - S.x2),
                     max(S.y1 - A.y2, A.y1 - S.y2) );
		//cout << d << '\n';
		if (d < 0) d = 0;
		ans += d;
		A.x1 -= d , A.x2 += d , A.y1 -= d , A.y2 += d;
		A.x1 = max(A.x1 , S.x1);
		A.x2 = min(A.x2 , S.x2);
		A.y1 = max(A.y1 , S.y1);
		A.y2 = min(A.y2 , S.y2);
	}
	cout << ans;


	return 0;
}
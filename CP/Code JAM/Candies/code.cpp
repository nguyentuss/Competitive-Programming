#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (2e5 + 7)
#define int long long

int v[MAX_N];
int IT1[4*MAX_N];
int IT2[4*MAX_N];
int f[MAX_N];

void build1(int index , int l , int r) {
	if (l == r) {
		IT1[index] = f[l - 1]*v[l];
		return;
	}
	int mid = (l + r)/2;
	build1(2*index , l , mid);
	build1(2*index + 1 , mid + 1 , r);
	IT1[index] = IT1[2*index] + IT1[2*index + 1];
}

void build2(int index , int l , int r) {
	if (l == r) {
		IT2[index] = f[l - 1]*v[l]*l;
		//cout << l << " " << IT2[index] << '\n';
		return;
	}
	int mid = (l + r)/2;
	build2(2*index , l , mid);
	build2(2*index + 1 , mid + 1 , r);
	IT2[index] = IT2[2*index] + IT2[2*index + 1];
}

void update1(int index , int l , int r , int i) {
	if (i < l || i > r) return;
	if (l == r) {
		IT1[index] = f[l - 1]*v[l];
		return;
	}
	int mid = (l + r)/2;
	update1(2*index , l , mid , i);
	update1(2*index + 1 , mid + 1 , r ,i);
	IT1[index] = IT1[2*index] + IT1[2*index + 1];
}

void update2(int index , int l , int r , int i) {
	if (i < l || i > r) return;
	if (l == r) {
		IT2[index] = f[l - 1]*v[l]*l;
		return;
	}
	int mid = (l + r)/2;
	update2(2*index , l , mid , i);
	update2(2*index + 1, mid + 1 , r , i);
	IT2[index] = IT2[2*index] + IT2[2*index + 1];
}

int get1(int index , int l , int r , int L , int R) {
	if (l > R || r < L) return 0;
	if (L <= l && r <= R) return IT1[index];
	int mid = (l + r)/2;
	return (get1(2*index , l , mid , L , R) +
		get1(2*index + 1 , mid + 1 , r , L , R));
}

int get2(int index , int l , int r , int L , int R) {
	if (l > R || r < L) return 0;
	if (L <= l && r <= R) return IT2[index];
	int mid = (l + r)/2;
	return (get2(2*index , l , mid , L , R) +
		get2(2*index + 1 , mid + 1 , r , L , R));
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("test.inp","r",stdin);
	f[0] = 1;
	for (int i = 1 ; i < MAX_N ; i++) {
		f[i] = f[i - 1]*(-1); 
	}
	int t; cin >> t;
	for (int test = 1 ; test <= t ; test++) {
		int n , q; cin >> n >> q;
		for (int i = 1 ; i <= 4*n ; i++) {
			IT1[i] = 0;
			IT2[i] = 0;
		}
		for (int i = 1 ; i <= n ; i++) 
			cin >> v[i];
		build1(1 , 1 , n);
		build2(1 , 1 , n);
		int ans = 0;
		for (int i = 1 ; i <= q ; i++) {
			char ask; cin >> ask;
			if (ask == 'Q') {
				int l , r; cin >> l >> r;
				//cout << get2(1 , 1 , n , 1 , 1) << '\n';
				int tmp = f[l - 1]*(get2(1 , 1 , n , 1 , r) - get2(1 , 1 , n , 1 , l - 1) 
				- (l - 1)*get1(1 , 1 , n , l , r));
				ans += tmp;
			}
			else {
				int x , u; cin >> u >> x;
				v[u] = x;
				update1(1 , 1 , n , u);
				update2(1 , 1 , n , u);
			}
		}
		cout << "Case #" << test << ": " << ans << '\n';
	}
	return 0;
}
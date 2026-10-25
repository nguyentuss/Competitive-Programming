#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)

struct seg {
	int val , lazy;
};

int a[MAX_N] , pos[MAX_N];
seg IT[4*MAX_N];
int f[MAX_N];

void down(int id) {
	int x = IT[id].lazy;
	IT[2*id].lazy = max(IT[2*id].lazy , IT[id].lazy);
	IT[2*id].val = max(IT[2*id].val , IT[id].lazy);
	IT[2*id + 1].lazy = max(IT[2*id + 1].lazy , IT[id].lazy);
	IT[2*id + 1].val = max(IT[2*id + 1].val , IT[id].lazy);
	IT[id].lazy = 0;
}

void update(int id , int l , int r , int queryL , int queryR , int x) {
	if (queryR < l || r < queryL) return;
	if (queryL <= l && r <= queryR) {
		IT[id].val = max(IT[id].val , x);
		IT[id].lazy = max(IT[id].lazy , x);
		return;
	}
	down(id);
	int mid = (l + r)/2;
	update(2*id , l , mid , queryL , queryR , x);
	update(2*id + 1 , mid + 1 , r , queryL , queryR , x);
	IT[id].val = max(IT[2*id].val , IT[2*id + 1].val);
	return;
}

int get(int id , int l , int r , int queryL , int queryR) {
	if (queryR < l || r < queryL) return 0;
	if (queryL <= l && r <= queryR) return IT[id].val;
	down(id);
	int mid = (l + r)/2;
	return max(get(2*id , l , mid , queryL , queryR),
	get(2*id + 1 , mid + 1 , r , queryL , queryR)
	);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	cout.tie(NULL);
	freopen("play.inp","r",stdin);
	freopen("play.out","w",stdout);
	int t; cin >> t;
	while (t--) {
		memset(f , 0 , sizeof f);
		memset(IT , 0 , sizeof IT);
		memset(pos , 0 , sizeof pos);
		int n , q , p; cin >> n >> p >> q;
		for (int i = 1 ; i <= p + 1 ; i++) 
			cin >> a[i];
		for (int i = 1 ; i <= q + 1; i++) { 
			int x; cin >> x;
			pos[x] = i;
		}
		for (int i = 1 ; i <= p + 1; i++) {
			if (pos[a[i]] != 0) {
				int x = get(1 , 1 , q + 1 , 1 , pos[a[i]]);
				f[i] = max(f[i] , x + 1);
			}	
			update(1 , 1 , q + 1 , pos[a[i]] , q + 1 , f[i]);
		}
		cout << f[p + 1] << '\n';
	}
	return 0;
}